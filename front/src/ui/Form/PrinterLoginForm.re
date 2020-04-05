let preventDefault = ReactEvent.Synthetic.preventDefault;

[@react.component]
let make = (~title) => {
  let (authenticationCode, setAuthenticationCode) = React.useState(() => "");

  let handleSubmit = evt => {
    preventDefault(evt);
    Authentication.setAuthCode(authenticationCode);
    Routing.push(PrinterHome)
  };

  MaterialUi.(
    <form onSubmit=handleSubmit>
      <Card>
        <CardContent>
          <Typography gutterBottom=true variant=`H5>
            {React.string(title)}
          </Typography>
          <FormInput
            value={`String(authenticationCode)}
            onChange=setAuthenticationCode
            label={{j|Code d'authentification|j}->React.string}
            placeholder="0000-0000-0000"
            required=true
          />
        </CardContent>
        <CardActions>
          <Button color=`Primary type_="submit">
            "Me connecter"->React.string
          </Button>
        </CardActions>
      </Card>
    </form>
  );
};
