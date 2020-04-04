'use strict';

var React = require("react");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var MaterialUi_Tab = require("@jsiebern/bs-material-ui/src/MaterialUi_Tab.bs.js");
var MaterialUi_Tabs = require("@jsiebern/bs-material-ui/src/MaterialUi_Tabs.bs.js");
var MaterialUi_Paper = require("@jsiebern/bs-material-ui/src/MaterialUi_Paper.bs.js");
var Core = require("@material-ui/core");
var Storybook$MaskManager = require("./Storybook.bs.js");

function test(param) {
  return React.createElement("div", undefined, "test");
}

function materialUi(param, param$1) {
  return React.createElement(Core.Paper, MaterialUi_Paper.makeProps(Caml_option.some(React.createElement(Core.Tabs, MaterialUi_Tabs.makeProps(undefined, Caml_option.some(null), undefined, undefined, /* Primary */-791844958, undefined, undefined, undefined, undefined, undefined, /* Primary */-791844958, undefined, undefined, undefined, undefined, undefined, undefined, /* () */0), React.createElement(Core.Tab, MaterialUi_Tab.makeProps(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, "Active", undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* () */0)), React.createElement(Core.Tab, MaterialUi_Tab.makeProps(undefined, undefined, true, undefined, undefined, undefined, undefined, undefined, "Disabled", undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* () */0)), React.createElement(Core.Tab, MaterialUi_Tab.makeProps(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, "Active", undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* () */0)))), undefined, undefined, undefined, true, undefined, undefined, undefined, undefined, undefined, /* () */0));
}

var $$default = Storybook$MaskManager.story(undefined, undefined, "Test");

exports.test = test;
exports.materialUi = materialUi;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* default Not a pure module */
