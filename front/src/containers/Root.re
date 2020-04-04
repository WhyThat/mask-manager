[@react.component]
let make = (~children) => (
  <ReasonApollo.Provider client=Client.instance>
    {children}
  </ReasonApollo.Provider>
)
