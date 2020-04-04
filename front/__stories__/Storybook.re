open Belt;

type title = string;
type includeStories = Js.Nullable.t(array(string));
type excludeStories = Js.Nullable.t(array(string));

type story = {
  title,
  excludeStories,
  includeStories,
};
let identity = a => a;

let toOption: 'a => option('a) = a => Some(a);

let story = (~includeStories=?, ~excludeStories=?, title) => {
  title,
  excludeStories:
    excludeStories
    ->Option.mapWithDefault([||], identity)
    ->Array.concat([|"$$default"|])
    ->toOption
    ->Js.Nullable.fromOption,
  includeStories: includeStories->Js.Nullable.fromOption,
};