[@bs.val] external document: Js.t({..}) = "document";

let makeContainer = () => {
  let container = document##createElement("div");

  let () = document##body##appendChild(container);

  container;
};

ReactDOMRe.render(<Root />, makeContainer());
