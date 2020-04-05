let formStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ());

let preventDefault = ReactEvent.Synthetic.preventDefault;

module Infix = {
  let (<$>) = Belt.Option.map;
  let (>>=) = Belt.Option.flatMap;
  let (|?) = Belt.Option.getWithDefault;
};

[@react.component]
let make = (~target="_self") => {
  let (firstName, setFirstName) = React.useState(() => "");
  let (lastName, setLastName) = React.useState(() => "");
  let (email, setEmail) = React.useState(() => "");
  let (phoneNumber, setPhoneNumber) = React.useState(() => "");
  let (customerType, setCustomerType) = React.useState(() => "");
  let (nbMask, setNbMask) = React.useState(() => 0);

  let (addCustomer, simple, _) =
    ApolloHooks.useMutation(Mutations.AddCustomerMutation.definition);
  let (addOrderMutation, _, _) =
    ApolloHooks.useMutation(Mutations.AddOrderMutation.definition);

  let addOrder = (nbMask, customerId) =>
    addOrderMutation(
      ~variables=
        Mutations.AddOrderMutation.makeVariables(
          ~count=nbMask,
          ~customerId,
          (),
        ),
    );

  React.useEffect1(
    () => {
      open Infix;
      switch (simple) {
      | Data(data) =>
        data##insert_customer
        >>= (
          insert_customer => insert_customer##returning->Belt.Array.get(0)
        )
        <$> (customer => customer##id)
        <$> addOrder(nbMask)
        |> ignore;
        ();
      | _ => Js.log("other")
      };
      None;
    },
    [|simple|],
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
          ~type_=customerType,
          (),
        ),
      (),
    )
    |> ignore;
  };

  MaterialUi.(
    <form autoComplete="off" style=formStyle onSubmit=handleSubmit>
      <FormInput
        value={`String(firstName)}
        onChange=setFirstName
        id="firstName"
        label={"Nom"->React.string}
      />
      <FormInput
        onChange=setLastName
        value={`String(lastName)}
        id="lastName"
        label={"Prenom"->React.string}
      />
      <FormInput
        onChange=setEmail
        value={`String(email)}
        type_="email"
        id="email"
        label={"Email"->React.string}
      />
      <FormInput
        onChange=setPhoneNumber
        value={`String(phoneNumber)}
        id="phoneNumber"
        label={"Telephone"->React.string}
        type_="phone"
      />
      <FormInput
        onChange=setCustomerType
        value={`String(customerType)}
        id="customerType"
        label={"Profession"->React.string}
        type_="phone"
      />
      <FormInput
        onChange=setNbMask
        value={`Int(nbMask)}
        id="nbMask"
        label={"Nombre de masques"->React.string}
        type_="number"
      />
      {switch (simple) {
       | Loading => React.string("loading...")
       | Error(error) =>
         Js.log(error);
         React.string("Something went wrong!");
       | Data(data) => React.string("youpi")
       | NotCalled =>
         <Button variant=`Contained type_="submit">
           "Valider"->React.string
         </Button>
       | NoData =>
         React.string(
           "Woa something went really wrong! Glady we use Reason and it forced us to handle this! Report this issue",
         )
       }}
    </form>
  );
};
