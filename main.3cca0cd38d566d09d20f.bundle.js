(window.webpackJsonp=window.webpackJsonp||[]).push([[0],{420:function(module,exports,__webpack_require__){"use strict";var Belt_Array=__webpack_require__(236),Belt_Option=__webpack_require__(80),Caml_option=__webpack_require__(12),Js_null_undefined=__webpack_require__(158);function identity(a){return a}exports.identity=identity,exports.toOption=function toOption(a){return Caml_option.some(a)},exports.story=function story(includeStories,excludeStories,title){return{title:title,excludeStories:Js_null_undefined.fromOption(Caml_option.some(Belt_Array.concat(Belt_Option.mapWithDefault(excludeStories,[],identity),["$$default"]))),includeStories:Js_null_undefined.fromOption(includeStories)}}},423:function(module,exports,__webpack_require__){"use strict";var React=__webpack_require__(0),Js_exn=__webpack_require__(780),Js_dict=__webpack_require__(237),Js_json=__webpack_require__(118),Js_option=__webpack_require__(782),Caml_array=__webpack_require__(421),ApolloHooks=__webpack_require__(783),Caml_option=__webpack_require__(12),Client$MaskManager=__webpack_require__(425),ReactHooks=__webpack_require__(119),ppx_printed_query="query UserQuery  {\nprinter  {\nfirstName  \n}\n\n}\n";function parse(value){var value$1=Js_option.getExn(Js_json.decodeObject(value)),match=Js_dict.get(value$1,"printer");return{printer:void 0!==match?Js_option.getExn(Js_json.decodeArray(Caml_option.valFromOption(match))).map((function(value){var tmp,value$1=Js_option.getExn(Js_json.decodeObject(value)),match=Js_dict.get(value$1,"firstName");if(void 0!==match){var match$1=Js_json.decodeString(Caml_option.valFromOption(match));tmp=void 0!==match$1?match$1:Js_exn.raiseError("Unexpected GraphQL query response")}else tmp=Js_exn.raiseError("Unexpected GraphQL query response");return{firstName:tmp}})):Js_exn.raiseError("Unexpected GraphQL query response")}}var definition=[parse,ppx_printed_query,function definition_002(graphql_ppx_use_json_variables_fn){return 0}];var UserQuery={ppx_printed_query:ppx_printed_query,query:ppx_printed_query,parse:parse,make:function make(param){return{query:ppx_printed_query,variables:null,parse:parse}},makeWithVariables:function makeWithVariables(param){return{query:ppx_printed_query,variables:null,parse:parse}},makeVariables:function makeVariables(param){return null},definition:definition,ret_type:function ret_type(f){return{}},MT_Ret:{}};var make$1=function TestGraphql(Props){var tmp,simple=ApolloHooks.useQuery(void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,definition)[0];return tmp="number"==typeof simple?0===simple?React.createElement("p",void 0,"Loading..."):React.createElement("p",void 0,"Get off my lawn!"):simple.tag?React.createElement("p",void 0,"Get off my lawn!"):React.createElement("p",void 0,Caml_array.caml_array_get(simple[0].printer,0).firstName),React.createElement(ReactHooks.ApolloProvider,{client:Client$MaskManager.instance,children:React.createElement("div",void 0,tmp)})};exports.UserQuery=UserQuery,exports.make=make$1},425:function(module,exports,__webpack_require__){"use strict";var ApolloLinks=__webpack_require__(789),Caml_option=__webpack_require__(12),ReasonApollo=__webpack_require__(794),inMemoryCache=__webpack_require__(802).createInMemoryCache(void 0,void 0,0),authHeaders={"x-hasura-admin-secret":"JeSuisMaskManager1234"},httpLink=ApolloLinks.createHttpLink("https://mask-manager-back-staging.herokuapp.com/v1/graphql",void 0,void 0,Caml_option.some(authHeaders),void 0,void 0,0),instance=ReasonApollo.createApolloClient(httpLink,inMemoryCache,void 0,void 0,void 0,void 0,0);exports.inMemoryCache=inMemoryCache,exports.authHeaders=authHeaders,exports.httpLink=httpLink,exports.instance=instance},437:function(module,exports,__webpack_require__){__webpack_require__(438),__webpack_require__(584),__webpack_require__(585),module.exports=__webpack_require__(748)},502:function(module,exports){},748:function(module,__webpack_exports__,__webpack_require__){"use strict";__webpack_require__.r(__webpack_exports__),function(module){var _storybook_react__WEBPACK_IMPORTED_MODULE_0__=__webpack_require__(426);module._StorybookPreserveDecorators=!0,Object(_storybook_react__WEBPACK_IMPORTED_MODULE_0__.configure)([__webpack_require__(776)],module)}.call(this,__webpack_require__(417)(module))},776:function(module,exports,__webpack_require__){var map={"./Storybook.bs.js":420,"./TestGraphql.bs.js":423,"./TestStories.bs.js":803};function webpackContext(req){var id=webpackContextResolve(req);return __webpack_require__(id)}function webpackContextResolve(req){if(!__webpack_require__.o(map,req)){var e=new Error("Cannot find module '"+req+"'");throw e.code="MODULE_NOT_FOUND",e}return map[req]}webpackContext.keys=function webpackContextKeys(){return Object.keys(map)},webpackContext.resolve=webpackContextResolve,module.exports=webpackContext,webpackContext.id=776},803:function(module,exports,__webpack_require__){"use strict";var React=__webpack_require__(0),Caml_option=__webpack_require__(12),MaterialUi_Tab=__webpack_require__(804),MaterialUi_Tabs=__webpack_require__(806),MaterialUi_Paper=__webpack_require__(807),Core=__webpack_require__(808),Client$MaskManager=__webpack_require__(425),ReactHooks=__webpack_require__(119),Storybook$MaskManager=__webpack_require__(420),TestGraphql$MaskManager=__webpack_require__(423);var $$default=Storybook$MaskManager.story(void 0,void 0,"Test");exports.test=function test(param){return React.createElement("div",void 0,"test")},exports.materialUi=function materialUi(param,param$1){return React.createElement(Core.Paper,MaterialUi_Paper.makeProps(Caml_option.some(React.createElement(Core.Tabs,MaterialUi_Tabs.makeProps(void 0,Caml_option.some(null),void 0,void 0,-791844958,void 0,void 0,void 0,void 0,void 0,-791844958,void 0,void 0,void 0,void 0,void 0,void 0,0),React.createElement(Core.Tab,MaterialUi_Tab.makeProps(void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,"Active",void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,0)),React.createElement(Core.Tab,MaterialUi_Tab.makeProps(void 0,void 0,!0,void 0,void 0,void 0,void 0,void 0,"Disabled",void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,0)),React.createElement(Core.Tab,MaterialUi_Tab.makeProps(void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,"Active",void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,void 0,0)))),void 0,void 0,void 0,!0,void 0,void 0,void 0,void 0,void 0,0))},exports.graphQl=function graphQl(param){return React.createElement(ReactHooks.ApolloProvider,{client:Client$MaskManager.instance,children:React.createElement(TestGraphql$MaskManager.make,{})})},exports.$$default=$$default,exports.default=$$default,exports.__esModule=!0}},[[437,1,2]]]);
//# sourceMappingURL=main.3cca0cd38d566d09d20f.bundle.js.map