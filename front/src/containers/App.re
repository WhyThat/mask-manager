[@react.component]
let make = () => {
  let route = Routing.getRouteFromUrl(ReasonReactRouter.useUrl().path);
  MaterialUi.(
    <>
      <AppBar position=`Static>
        <Toolbar>
          <Typography variant=`H6>
            {React.string("Mask Manager")}
          </Typography>
        </Toolbar>
      </AppBar>
      {switch (route) {
       | Home => <Home />
       | CustomerRegister => <div />
       | PrinterRegister => <PrinterRegister />
       | OrderStatus(orderId) => <div />
       | PrintingEdit(printingId) => <div />
       | PrinterHome => <PrinterHome />
       | PrintingList => <div />
       | PrintersList => <div />
       | CustomersList => <div />
       | _ => React.string("Not found")
       }}
    </>
  );
};
