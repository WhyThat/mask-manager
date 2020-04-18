open Storybook;

let registerCustomer = () => {
  <ApolloHooks.Provider client=Client.instance>
    <div style={ReactDOMRe.Style.make(~width="300px", ())}>
      <CustomerForm title="customer form" />
    </div>
  </ApolloHooks.Provider>;
};

let registerPrinter = () => {
  <ApolloHooks.Provider client=Client.instance>
    <div style={ReactDOMRe.Style.make(~width="300px", ())}>
      <PrinterForm title="printer Form" />
    </div>
  </ApolloHooks.Provider>;
};

let addPrinting = () => {
  <ApolloHooks.Provider client=Client.instance>
    <div style={ReactDOMRe.Style.make(~width="300px", ())}>
      <AddPrinting
        orderId={"a8432c16-5e91-459f-af32-32beb49de614"->Js.Json.string}
        title="printer Form"
      />
    </div>
  </ApolloHooks.Provider>;
};

let default = story("Forms");
