let inputStyle = ReactDOMRe.Style.make(~paddingBottom="8px", ());

[@react.component]
let make = (~id=?, ~name=id, ~label, ~value, ~onChange, ~type_=?, ~placeholder=?, ~required=?) => {
  let handleChange = event => onChange(ReactEvent.Form.target(event)##value);
  MaterialUi.(
    <TextField
      style=inputStyle
      ?required
      ?id
      ?name
      label
      value
      fullWidth=true
      onChange=handleChange
      ?type_
      ?placeholder
    />
  );
};
