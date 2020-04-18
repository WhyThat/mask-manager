open! Opt.Infix;

let formStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ());

let preventDefault = ReactEvent.Synthetic.preventDefault;

let getIdFromGraphQl = obj =>
  obj##returning->Belt.Array.get(0) <$> (obj => obj##id);

[@react.component]
let make = (~orderId, ~title) => {
  let (simple, _full) = Queries.usePrintersListQuery();
  let (count, setCount) = React.useState(() => 0);
  let (printerId, setPrinterId) = React.useState(() => None);
  let (addPrinting, addPrintingStatus, _) =
    ApolloHooks.useMutation(Mutations.AddPrintingMutation.definition);

  let addPrinting = (~count, ~printerId, ~orderId) => {
    addPrinting(
      ~variables=
        Mutations.AddPrintingMutation.makeVariables(
          ~count,
          ~printerId=printerId->Js.Json.string,
          ~orderId,
          (),
        ),
      (),
    )
    |> ignore;
  };

  let handleSubmit = event => {
    ReactEvent.Form.preventDefault(event);
    switch (printerId, count > 0) {
    | (Some(printerId), true) => addPrinting(~count, ~orderId, ~printerId)
    | _ => ()
    };
  };

  let setPrinterId = (event, _) => {
    setPrinterId(_ => Some(ReactEvent.Form.target(event)##value));
  };

  MaterialUi.(
    <Card>
      <form autoComplete="off" style=formStyle onSubmit=handleSubmit>
        <CardContent>
          <Typography gutterBottom=true variant=`H5>
            {React.string(title)}
          </Typography>
          <Grid container=true spacing=V6>
            <Grid item=true md=V6 xs=V12>
              <FormInput
                value={`Int(count)}
                onChange=setCount
                type_="number"
                id="count"
                label={"Nombre de masque à imprimer"->React.string}
              />
            </Grid>
            <Grid item=true md=V6 xs=V12>
              {switch (simple) {
               | Loading => React.string("loading...")
               | Data(data) =>
                 <Select
                   onChange=setPrinterId
                   labelId="demo-simple-select-label"
                   id="demo-simple-select">
                   {data##printer
                    ->Belt.Array.map(printer =>
                        <MenuItem
                          value={
                                  `String(
                                    printer##id
                                    ->Js.Json.decodeString
                                    ->Belt.Option.getWithDefault(""),
                                  )
                                }>
                          {printer##firstName->React.string}
                          " "->React.string
                          {printer##lastName->React.string}
                        </MenuItem>
                      )}
                 </Select>
               | NoData
               | Error(_) => React.string("Something went wrong!")
               }}
            </Grid>
          </Grid>
        </CardContent>
        <CardActions>
          {switch (addPrintingStatus) {
           | NotCalled =>
             <Button variant=`Contained type_="submit">
               "Valider"->React.string
             </Button>
           | Loading => React.string({j|Chargement|j})
           | Data(_) =>
             React.string({j| Affectation de la commande effectuée|j})
           | NoData => "pas de données"->React.string
           | Error(_) => "Error"->React.string
           }}
        </CardActions>
      </form>
    </Card>
  );
};
