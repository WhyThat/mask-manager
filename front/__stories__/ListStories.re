open Storybook;

let listOrders = () => {
  <ApolloHooks.Provider client=Client.instance>
      <OrdersList />
  </ApolloHooks.Provider>;
};

let default = story("Lists");
