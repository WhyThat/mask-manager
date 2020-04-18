[@react.component]
let make = () => {
  React.useEffect0(() => {
    if (Authentication.isAuthenticated()) {
      Routing.push(PrinterHome);
    };
    None;
  });

  MaterialUi.(
    <Grid container=true spacing=V6>
      <Grid item=true md=V3 />
      <Grid item=true md=V6>
        <PrinterForm title={j| Créer un compte imprimeur |j} />
      </Grid>
      <Grid item=true md=V3 />
      <Grid item=true md=V3 />
      <Grid item=true md=V6>
        <PrinterLoginForm title={j| Je possède déjà un compte |j} />
      </Grid>
      <Grid item=true md=V3 />
    </Grid>
  );
};
