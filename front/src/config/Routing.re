type route =
  | Home
  | CustomerRegister
  | PrinterRegister
  | OrderStatus(string)
  | PrintingEdit(string)
  | PrinterHome
  | PrintingList
  | PrintersList
  | CustomersList
  | NotFound

let getRoutePath = route => switch(route) {
  | Home => "/"
  | CustomerRegister => "/customers/register"
  | PrinterRegister => "/printers/register"
  | OrderStatus(orderId) => "/orders/" ++ orderId ++ "/status"
  | PrintingEdit(printingId) => "/printings/" ++ printingId ++ "/edit"
  | PrinterHome => "/printers/me"
  | PrintingList => "/printings"
  | PrintersList => "/printers"
  | CustomersList => "/customers"
  | NotFound => "/404"
}

let getRouteFromUrl = url => switch(url) {
  | [] => Home
  | ["customers", "register"] => CustomerRegister
  | ["printers", "register"] => PrinterRegister
  | ["orders", orderId, "status"] => OrderStatus(orderId)
  | ["printings", printingId, "edit"] => PrintingEdit(printingId)
  | ["printers", "me"] => PrinterHome
  | ["printings"] => PrintingList
  | ["printers"] => PrintersList
  | ["customers"] => CustomersList
  | _ => NotFound
}

let push = route => ReasonReactRouter.push(getRoutePath(route))
