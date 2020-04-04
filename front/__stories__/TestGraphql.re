open ApolloHooks;

module UserQuery = [%graphql
  {|
  query UserQuery {
    printer {
      firstName
    }
  }
|}
];

[@react.component]
let make = () => {
  /* Both variant and records available */
  let (simple, _full) = useQuery(UserQuery.definition);

  <ApolloHooks.Provider client=Client.instance>
    <div>
      {switch (simple) {
       | Loading => <p> {React.string("Loading...")} </p>
       | Data(data) => <p> {React.string(data##printer[0]##firstName)} </p>
       | NoData
       | Error(_) => <p> {React.string("Get off my lawn!")} </p>
       }}
    </div>
  </ApolloHooks.Provider>;
};
