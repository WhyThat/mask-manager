[@react.component]
let make = () => {
  MaterialUi.(
    <Grid container=true spacing=V6>
      <Grid item=true md=V3 />
      <Grid item=true md=V6>
        <CustomerForm title={j| Créer un compte et un commande |j} />
      </Grid>
      <Grid item=true md=V3 />
      <Grid item=true md=V3 />
      <Grid item=true md=V6>
        {React.string("Voir l'avancer d'une commande")}
      </Grid>
      <Grid item=true md=V3 />
    </Grid>
  );
};
