let inputStyle = ReactDOMRe.Style.make(~paddingBottom="8px", ());

[@react.component]
let make = (~id, ~label, ~type_=?) =>
  MaterialUi.(
    <TextField
      style=inputStyle
      _InputLabelProps={"shrink": true}
      required=true
      id
      label
      ?type_
    />
  );