module Infix = {
  let (<$>) = Belt.Option.map;
  let (>>=) = Belt.Option.flatMap;
  let (|?) = Belt.Option.getWithDefault;
};

