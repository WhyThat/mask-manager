[@react.component]
let make = (~target, ~children) => <a href={Routing.getRoutePath(target)}>children</a>
