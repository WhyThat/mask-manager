'use strict';

var React = require("react");
var ReactDom = require("react-dom");
var ExampleStyles$MaskManager = require("./ExampleStyles.bs.js");
var BlinkingGreeting$MaskManager = require("./BlinkingGreeting/BlinkingGreeting.bs.js");
var FetchedDogPictures$MaskManager = require("./FetchedDogPictures/FetchedDogPictures.bs.js");
var ReducerFromReactJSDocs$MaskManager = require("./ReducerFromReactJSDocs/ReducerFromReactJSDocs.bs.js");
var ReasonUsingJSUsingReason$MaskManager = require("./ReasonUsingJSUsingReason/ReasonUsingJSUsingReason.bs.js");

var style = document.createElement("style");

document.head.appendChild(style);

style.innerHTML = ExampleStyles$MaskManager.style;

function makeContainer(text) {
  var container = document.createElement("div");
  container.className = "container";
  var title = document.createElement("div");
  title.className = "containerTitle";
  title.innerText = text;
  var content = document.createElement("div");
  content.className = "containerContent";
  container.appendChild(title);
  container.appendChild(content);
  document.body.appendChild(container);
  return content;
}

ReactDom.render(React.createElement(BlinkingGreeting$MaskManager.make, {
          children: "Hello!"
        }), makeContainer("Blinking Greeting"));

ReactDom.render(React.createElement(ReducerFromReactJSDocs$MaskManager.make, { }), makeContainer("Reducer From ReactJS Docs"));

ReactDom.render(React.createElement(FetchedDogPictures$MaskManager.make, { }), makeContainer("Fetched Dog Pictures"));

ReactDom.render(React.createElement(ReasonUsingJSUsingReason$MaskManager.make, { }), makeContainer("Reason Using JS Using Reason"));

var t = "";

exports.t = t;
exports.style = style;
exports.makeContainer = makeContainer;
/* style Not a pure module */
