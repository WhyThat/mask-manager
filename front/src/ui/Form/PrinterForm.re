let formStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ());

let preventDefault = ReactEvent.Synthetic.preventDefault;

[@react.component]
let make = (~target="_self", ~onSubmit) => {
  let (firstName, setFirstName) = React.useState(() => `String(""));
  let (lastName, setLastName) = React.useState(() => `String(""));
  let (email, setEmail) = React.useState(() => `String(""));
  let (phoneNumber, setPhoneNumber) = React.useState(() => `String(""));
  let (nbPrinters, setNbPrinters) = React.useState(() => `Int(0));

  let handleSubmit = evt => {
    preventDefault(evt);
    Js.log(evt);
    onSubmit();
  };

  MaterialUi.(
    <form autoComplete="off" style=formStyle onSubmit=handleSubmit>
      <FormInput
        value=firstName
        onChange=setFirstName
        id="firstName"
        label={"Nom"->React.string}
      />
      <FormInput onChange=setLastName value=lastName id="lastName" label={"Prenom"->React.string} />
      <FormInput onChange=setEmail value=email id="email" label={"Email"->React.string} />
      <FormInput
        onChange=setPhoneNumber
        value=phoneNumber
        id="phoneNumber"
        label={"Telephone"->React.string}
        type_="phone"
      />
      <FormInput
        onChange=setNbPrinters
        value=nbPrinters
        id="nbPrinters"
        label={"Nombre d'imprimantes"->React.string}
        type_="number"
      />
      <Button variant=`Contained type_="Submit">
        "Valider"->React.string
      </Button>
    </form>
  );
};
