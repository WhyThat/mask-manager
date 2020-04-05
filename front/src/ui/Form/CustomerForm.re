open! Opt.Infix;

let formStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ());

let preventDefault = ReactEvent.Synthetic.preventDefault;

let getIdFromGraphQl = obj =>
  obj##returning->Belt.Array.get(0) <$> (obj => obj##id);

[@react.component]
let make = (~target="_self", ~title) => {
  let (firstName, setFirstName) = React.useState(() => "");
  let (lastName, setLastName) = React.useState(() => "");
  let (email, setEmail) = React.useState(() => "");
  let (phoneNumber, setPhoneNumber) = React.useState(() => "");
  let (customerType, setCustomerType) = React.useState(() => "");
  let (nbMask, setNbMask) = React.useState(() => 0);

  let (addCustomer, customerStatus, _) =
    ApolloHooks.useMutation(Mutations.AddCustomerMutation.definition);
  let (addOrderMutation, orderStatus, _) =
    ApolloHooks.useMutation(Mutations.AddOrderMutation.definition);

  let addOrder = (nbMask, customerId) =>
    addOrderMutation(
      ~variables=
        Mutations.AddOrderMutation.makeVariables(
          ~count=nbMask,
          ~customerId,
          ~productId=Js.Json.string("5e0afa8d-7c7d-4f0b-93e0-5f017c3a9872"),
          (),
        ),
      (),
    );

  let handleSubmit = evt => {
    preventDefault(evt);
    addCustomer(
      ~variables=
        Mutations.AddCustomerMutation.makeVariables(
          ~firstName,
          ~lastName,
          ~email,
          ~phoneNumber,
          ~customerType,
          (),
        ),
      (),
    )
    |> Js.Promise.then_(
         (
           (result: ApolloHooksMutation.executionVariantResult('customer), _),
         ) => {
         switch (result) {
         | Data(customer) =>
           customer##insert_customer
           >>= getIdFromGraphQl
           <$> addOrder(nbMask)
           <$> Js.Promise.then_(
                 (
                   (
                     result:
                       ApolloHooksMutation.executionVariantResult('order),
                     _,
                   ),
                 ) =>
                 (
                   switch (result) {
                   | Data(data) =>
                     data##insert_order
                     >>= getIdFromGraphQl
                     >>= Js.Json.decodeString
                     |> Belt.Option.forEach(_, orderId =>
                          Routing.push(Routing.OrderStatus(orderId))
                        )
                   | _ => ()
                   }
                 )
                 |> Js.Promise.resolve
               )
           |> ignore

         | Errors(error) => Js.Console.log(error)
         | _ => Js.Console.log("🤷")
         };
         Js.Promise.resolve();
       })
    |> ignore;
  };

  MaterialUi.(
    <Card>
      <form autoComplete="off" style=formStyle onSubmit=handleSubmit>
        <CardContent>
          <Typography gutterBottom=true variant=`H5>
            {React.string(title)}
          </Typography>
          <Grid container=true spacing=V3>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                value={`String(firstName)}
                onChange=setFirstName
                id="firstName"
                label={"Nom"->React.string}
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                onChange=setLastName
                value={`String(lastName)}
                id="lastName"
                label={"Prenom"->React.string}
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                onChange=setEmail
                value={`String(email)}
                type_="email"
                id="email"
                label={"Email"->React.string}
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                onChange=setPhoneNumber
                value={`String(phoneNumber)}
                id="phoneNumber"
                label={"Telephone"->React.string}
                type_="phone"
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                onChange=setCustomerType
                value={`String(customerType)}
                id="customerType"
                label={"Profession"->React.string}
                type_="phone"
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                onChange=setNbMask
                value={`Int(nbMask)}
                id="nbMask"
                label={"Nombre de masques"->React.string}
                type_="number"
              />
            </Grid>
          </Grid>
        </CardContent>
        <CardActions>
          {switch (customerStatus, orderStatus) {
           | (NotCalled, _) =>
             <Button variant=`Contained type_="submit">
               "Valider"->React.string
             </Button>
           | (Loading, _) =>
             React.string({j|Création du compte utilisateur ...|j})
           | (Data(_), NotCalled | Loading) =>
             React.string({j| Création de la commande ...|j})
           | (Data(_), Data(_)) =>
             React.string(
               {j|La commande a été enregistré, vous allez etre redirigé ...|j},
             )
           | _ => React.string("Troubles ")
           }}
        </CardActions>
      </form>
    </Card>
  );
};
