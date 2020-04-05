open Storybook;

let registerCustomer = () => {
  <ApolloHooks.Provider client=Client.instance>
    <div style={ReactDOMRe.Style.make(~width="300px", ())}>
      <CustomerForm />
    </div>
  </ApolloHooks.Provider>;
};

let registerPrinter = () => {
  <ApolloHooks.Provider client=Client.instance>
    <div style={ReactDOMRe.Style.make(~width="300px", ())}>
      <PrinterForm />
    </div>
  </ApolloHooks.Provider>;
};

let default = story("Forms");
