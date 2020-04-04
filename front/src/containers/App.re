[@react.component]
let make = () => {
  let route = Routing.getRouteFromUrl(ReasonReactRouter.useUrl().path)
  MaterialUi.(
    <>
      <AppBar position={`Static}>
        <Toolbar>
          <Typography variant={`H6}>
           {React.string("Mask Manager")}
          </Typography>
        </Toolbar>
      </AppBar>
      {switch (route) {
        | Home => <Home />
        | CustomerRegister => <div />
        | PrinterRegister => <div />
        | OrderStatus(orderId) => <div />
        | PrintingEdit(printingId) => <div />
        | PrinterHome => <div />
        | PrintingList => <div />
        | PrintersList => <div />
        | CustomersList => <div />
        | _ => {React.string("Not found")}
      }}
    </>
  );
}
