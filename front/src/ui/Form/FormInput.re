let inputStyle = ReactDOMRe.Style.make(~paddingBottom="8px", ());

[@react.component]
let make = (~id, ~label, ~value, ~onChange, ~type_=?) => {
  let handleChange = event => onChange(ReactEvent.Form.target(event)##value);
  MaterialUi.(
    <TextField
      style=inputStyle
      _InputLabelProps={"shrink": true}
      required=true
      id
      label
      value
      onChange=handleChange
      ?type_
    />
  );
};