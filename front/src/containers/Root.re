[@react.component]
let make = (~children) => (
  <ApolloHooks.Provider client=Client.instance>
    {children}
  </ApolloHooks.Provider>
)
