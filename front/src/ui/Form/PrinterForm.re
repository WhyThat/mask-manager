let formStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ());

let preventDefault = ReactEvent.Synthetic.preventDefault;

[@react.component]
let make = (~target="_self") => {
  let (firstName, setFirstName) = React.useState(() => "");
  let (lastName, setLastName) = React.useState(() => "");
  let (email, setEmail) = React.useState(() => "");
  let (phoneNumber, setPhoneNumber) = React.useState(() => "");
  let (printerCount, setNbPrinters) = React.useState(() => 0);
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
        onChange=setNbPrinters
        value={`Int(printerCount)}
        id="nbPrinters"
        label={"Nombre d'imprimantes"->React.string}
        type_="number"
      />
      <Button variant=`Contained type_="submit">
        "Valider"->React.string
      </Button>
    </form>
  );
};
