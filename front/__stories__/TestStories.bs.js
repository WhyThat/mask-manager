'use strict';

var React = require("react");
var Storybook$MaskManager = require("./Storybook.bs.js");

function test(param) {
  return React.createElement("div", undefined, "test");
}

var $$default = Storybook$MaskManager.story(undefined, undefined, "Test");

exports.test = test;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* default Not a pure module */
