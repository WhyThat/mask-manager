open Storybook;

let make = ((), ()) => {
  let (count, setCount) = React.useState(() => 0);
  let handleSubmit = () => {
    Js.log("yay");
  };

  <div style={ReactDOMRe.Style.make(~width="300px", ())}>
    <PrinterForm onSubmit=handleSubmit />
  </div>;
};

let default = story("CustomerForm");