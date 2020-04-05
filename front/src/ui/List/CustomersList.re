let formStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ());

let preventDefault = ReactEvent.Synthetic.preventDefault;

let makeTitle = (firstName, lastName) =>
  {
    firstName ++ " " ++ lastName;
  }
  ->React.string;

let makeSubTitle = (email, phoneNumber) =>
  {
    "Email: "
    ++ email
    ++ (
      switch (phoneNumber) {
      | Some(phoneNumber) => " telephone: " ++ phoneNumber
      | None => ""
      }
    );
  }
  ->React.string;

[@react.component]
let make = () => {
  let (selectedCustomer, setSelectedCustomer) = React.useState(() => "");

  let handleClick = (id: string, _e) =>
    setSelectedCustomer(_ => id === selectedCustomer ? "" : id);
  //;
  //let isSelected = (~id) => id === selectedCustomer;
  let (simple, _full) = Queries.useCustomersListQuery();

  MaterialUi.(
    <List subheader={<ListSubheader> "Customers list" </ListSubheader>}>
      {switch (simple) {
       | Loading => React.string("loading...")
       | Data(data) =>
         data##customer
         ->Belt.Array.map(c => {
             <>
               <ListItem button=true onClick={handleClick(c##email)}>
                 <ListItemText
                   primary={makeTitle(c##firstName, c##lastName)}
                   secondary={makeSubTitle(c##email, c##phoneNumber)}
                 />
                 {c##email === selectedCustomer
                    ? <MaskManager.Icon.ExpandLess />
                    : <MaskManager.Icon.ExpandMore />}
               </ListItem>
               {c##email === selectedCustomer
                  ? <Collapse in_={c##email === selectedCustomer}>
                      <OrdersList customerId={c##id} />
                    </Collapse>
                  : ReasonReact.null}
             </>
           })
         |> ReasonReact.array
       | NoData
       | Error(_) => React.string("Something went wrong!")
       }}
    </List>
  );
};