[@react.component]
let make = () => (
  <ApolloHooks.Provider client=Client.instance>
    <App />
  </ApolloHooks.Provider>
)
