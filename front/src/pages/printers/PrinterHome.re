[@react.component]
let make = () => {
  let (response, _) =
    Queries.usePrinterDetailsQuery(Authentication.getAuthCode());

  React.useEffect0(() => {
    if (!Authentication.isAuthenticated()) {
      Routing.push(PrinterRegister);
    };

    // Logout if user is unkown
    switch (response) {
    | Data(data) =>
      switch (data##printer_by_pk) {
      | None => Authentication.logout()
      | _ => ()
      }
    | _ => ()
    };

    None;
  });

  switch (response) {
  | Data(data) =>
    switch (data##printer_by_pk) {
    | Some(printer) =>
      MaterialUi.(
        <Grid container=true spacing=V3>
          <Grid item=true md=V2 />
          <Grid item=true md=V8>
            <Card>
              <CardContent>
                <Typography gutterBottom=true variant=`H5>
                  {React.string("Bonjour " ++ printer##firstName)}
                </Typography>
              </CardContent>
            </Card>
          </Grid>
          <Grid item=true md=V2 />
        </Grid>
      )
    | None => React.null
    }
  | _ => React.string("Unknown error.")
  };
};
