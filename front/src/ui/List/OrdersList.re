open Opt.Infix;

let prependZero = str => str |> Js.String.length < 2 ? "0" ++ str : str;
let toInputDateFormat = date => {
  let str = value => string_of_int @@ Js.Math.floor @@ value;

  let month = date |> Js.Date.getMonth |> (+.)(1.0) |> str |> prependZero;
  let day = date |> Js.Date.getDate |> str |> prependZero;
  let year = date |> Js.Date.getFullYear |> str;

  year ++ "-" ++ month ++ "-" ++ day;
};

let style= ReactDOMRe.Style.make(~width="100%", ());
[@react.component]
let make = () => {
  let (simple, _full) = Queries.useOrdersListQuery();

  MaterialUi.(
    <TableContainer style >
      <Table>
        <TableHead>
          <TableRow>
            <TableCell> "Nom du demandeur"->React.string </TableCell>
            <TableCell> {j|Prénom du demandeur|j}->React.string </TableCell>
            <TableCell>
            {j|Date de création de la commande|j}->React.string
            </TableCell>
            <TableCell> "Nombre de masque"->React.string </TableCell>
            <TableCell> {j|Nombre imnrimé|j}->React.string </TableCell>
            <TableCell> "Nombre en cours d'impression"->React.string </TableCell>
            <TableCell> {j|Déjà livré|j}->React.string </TableCell>
          </TableRow>
        </TableHead>
        <TableBody>
          {switch (simple) {
           | Loading => React.string("loading...")
           | Data(data) =>
             data##order
             ->Belt.Array.map(order => {
                 let id =
                   Js.Json.decodeString(order##id)
                   ->Belt.Option.getWithDefault("");
                 let createdAt =
                   order##createdAt
                   ->Js.Json.decodeString
                   ->Belt.Option.getWithDefault("");
                 <TableRow key=id>
                   <TableCell>
                     {order##customer##firstName->React.string}
                   </TableCell>
                   <TableCell>
                     {order##customer##lastName->React.string}
                   </TableCell>
                   <TableCell>
                     {Js.Date.fromString(createdAt)
                      ->toInputDateFormat
                      ->React.string}
                   </TableCell>
                   <TableCell>
                     {order##count->string_of_int->React.string}
                   </TableCell>
                   <TableCell>
                     {order##printedCount->string_of_int->React.string}
                   </TableCell>
                   <TableCell>
                     {order##pendingPrintCount->string_of_int->React.string}
                   </TableCell>
                   <TableCell>
                     {order##deliveryCount->string_of_int->React.string}
                   </TableCell>
                 </TableRow>;
               })
             ->ReasonReact.array;
           | NoData
           | Error(_) => React.string("Something went wrong!")
           }}
        </TableBody>
      </Table>
    </TableContainer>
  );
};
