let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let authHeaders = Js.Dict.empty(());
Js.Dict.set(authHeaders, "x-hasura-admin-secret", Js.Json.string("JeSuisMaskManager1234"));

let httpLink =
  ApolloLinks.createHttpLink(~uri="https://mask-manager-back-staging.herokuapp.com/v1/graphql", ~headers=Js.Json.object_(authHeaders), ());

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());
