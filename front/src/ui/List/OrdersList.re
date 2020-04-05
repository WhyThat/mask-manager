[@react.component]
let make = (~customerId) => {
  let (simple, _full) = Queries.useOrderDetailsQuery(customerId);

  MaterialUi.(
    <List subheader={<ListSubheader> "Order list" </ListSubheader>}>
      {switch (simple) {
       | Loading => React.string("loading...")
       | Data(data) =>
         Js.log(data);
         <> </>;
       /*data##order_by_pk
         ->Belt.Array.map(c => {
             <>
               <ListItem>
                 <ListItemText primary={"tada"->React.string} />
               </ListItem>
             </>
           })
         |> ReasonReact.array*/
       | NoData
       | Error(_) => React.string("Something went wrong!")
       }}
    </List>
  );
};