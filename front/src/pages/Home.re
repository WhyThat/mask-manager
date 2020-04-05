[@react.component]
let make = () =>
  MaterialUi.(
    <Grid container=true justify=`Center>
      <Grid item=true xs=V12 />
      <Grid item=true md=V6>
        <Typography variant=`H1 gutterBottom=true>
          {React.string("Bienvenue")}
        </Typography>
        <RouteLink target={Routing.PrinterHome}>
          <Button variant=`Contained color=`Primary>
            {React.string("Je veux imprimer")}
          </Button>
        </RouteLink>
        <RouteLink target={Routing.CustomerRegister}>
          <Button variant=`Contained color=`Primary>
            {React.string("Je veux commander")}
          </Button>
        </RouteLink>
      </Grid>
    </Grid>
  );

