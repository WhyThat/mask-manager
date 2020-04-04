let t = "";

[@bs.val] external document: Js.t({..}) = "document";

let makeContainer = () => {
  let container = document##createElement("div");

  let () = document##body##appendChild(container);

  container;
};

ReactDOMRe.render(
  <Root>
    {React.string("Hello!")}
  </Root>,
  makeContainer(),
);
