let formStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ());

let preventDefault = event => ReactEventRe.Synthetic.preventDefault(event);

[@react.component]
let make = (~target="_self", ~onSubmit) => {
  let (name, setName) = React.useState(() => "");

  let handleSubmit = evt => {
    preventDefault(evt);
    Js.log(evt);
    onSubmit();
  };

  MaterialUi.(
    <form autoComplete="off" style=formStyle onSubmit=handleSubmit>
      <FormInput id="firstName" label={"Nom"->React.string} />
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