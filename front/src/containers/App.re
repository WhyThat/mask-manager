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
        | Home => <div />
        | CustomerRegister => <div />
        | PrinterRegister => <div />
        | OrderStatus(string) => <div />
        | PrintingEdit(string) => <div />
        | PrinterHome => <div />
        | PrintingList => <div />
        | PrintersList => <div />
        | CustomersList => <div />
        | _ => {React.string("Not found")}
      }}
    </>
  );
}
