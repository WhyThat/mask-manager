open Storybook;

let listCustomers = () => {
  <ApolloHooks.Provider client=Client.instance>
    <div style={ReactDOMRe.Style.make(~width="600px", ())}>
      <CustomersList />
    </div>
  </ApolloHooks.Provider>;
};

let default = story("Lists");