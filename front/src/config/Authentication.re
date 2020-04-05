[@bs.val] [@bs.scope "localStorage"] external getItem: string => Js.Nullable.t(string) = "getItem";
[@bs.val] [@bs.scope "localStorage"] external setItem: (string, string) => unit = "setItem";
[@bs.val] [@bs.scope "localStorage"] external removeItem: string => unit = "removeItem";

let token_localstorage_key = "userId";

let getAuthCode = () =>
  getItem(token_localstorage_key) |> Js.Nullable.toOption;

let setAuthCode = code => setItem(token_localstorage_key, code);

let isAuthenticated = () => getAuthCode() |> Belt.Option.isSome;

let logout = () => {
  removeItem(token_localstorage_key);
  Routing.push(Home);
};
