let formStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ());

let preventDefault = event => ReactEventRe.Synthetic.preventDefault(event);

[@react.component]
let make = (~target="_self", ~onSubmit) => {
  let (firstName, setFirstName) = React.useState(() => "");
  let (lastName, setLastName) = React.useState(() => "");
  let (email, setEmail) = React.useState(() => "");
  let (phoneNumber, setPhoneNumber) = React.useState(() => 0);
  let (nbPrinters, setNbPrinters) = React.useState(() => 0);

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
      <FormInput id="lastName" label={"Prenom"->React.string} />
      <FormInput id="email" label={"Email"->React.string} />
      <FormInput
        id="phoneNumber"
        label={"Telephone"->React.string}
        type_="number"
      />
      <FormInput
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