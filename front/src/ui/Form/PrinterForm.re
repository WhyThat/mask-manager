let preventDefault = ReactEvent.Synthetic.preventDefault;

[@react.component]
let make = (~title) => {
  let (firstName, setFirstName) = React.useState(() => "");
  let (lastName, setLastName) = React.useState(() => "");
  let (email, setEmail) = React.useState(() => "");
  let (phoneNumber, setPhoneNumber) = React.useState(() => "");
  let (printerCount, setNbPrinters) = React.useState(() => 1);
  let (addPrinter, _, _) = Mutations.useAddPrinterMutation();

  let handleSubmit = evt => {
    preventDefault(evt);
    addPrinter(
      ~variables=
        Mutations.AddPrinterMutation.makeVariables(
          ~firstName,
          ~lastName,
          ~email,
          ~phoneNumber,
          ~printerCount,
          (),
        ),
      (),
    )
    |> Js.Promise.then_(
         fun
         | _ => Js.Promise.resolve(Js.log("ok")),
       )
    |> ignore;
  };

  MaterialUi.(
    <Card>
      <form onSubmit=handleSubmit>
        <CardContent>
          <Typography gutterBottom=true variant=`H5>
            {React.string(title)}
          </Typography>
          <Grid container=true spacing=V3>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                value={`String(firstName)}
                onChange=setFirstName
                id="lastName"
                label={"Nom"->React.string}
                placeholder="John"
                required=true
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                onChange=setLastName
                value={`String(lastName)}
                id="firstName"
                label={"Prenom"->React.string}
                placeholder="Doe"
                required=true
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                onChange=setEmail
                value={`String(email)}
                type_="email"
                id="email"
                label={"Email"->React.string}
                placeholder="john.doe@acme.com"
                required=true
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                onChange=setPhoneNumber
                value={`String(phoneNumber)}
                id="phoneNumber"
                label={"Telephone"->React.string}
                type_="phone"
                placeholder="0601020304"
              />
            </Grid>
            <Grid item=true md=V12>
              <FormInput
                onChange=setNbPrinters
                value={`Int(printerCount)}
                id="nbPrinters"
                label={"Nombre d'imprimantes"->React.string}
                type_="number"
                required=true
              />
            </Grid>
          </Grid>
        </CardContent>
        <CardActions>
          <Button color=`Primary type_="submit">
            "Valider"->React.string
          </Button>
        </CardActions>
      </form>
    </Card>
  );
};
