'use strict';

var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Js_null_undefined = require("bs-platform/lib/js/js_null_undefined.js");

function identity(a) {
  return a;
}

function toOption(a) {
  return Caml_option.some(a);
}

function story(includeStories, excludeStories, title) {
  return {
          title: title,
          excludeStories: Js_null_undefined.fromOption(Caml_option.some(Belt_Array.concat(Belt_Option.mapWithDefault(excludeStories, [], identity), ["$$default"]))),
          includeStories: Js_null_undefined.fromOption(includeStories)
        };
}

exports.identity = identity;
exports.toOption = toOption;
exports.story = story;
/* No side effect */
