open ApolloHooks;

module GetPrintersListQuery = [%graphql
  {|
    query GetPrintersList {
      printer {
        id
        firstName
        lastName
        email
        phoneNumber
        printerCount
        printings_aggregate {
          aggregate {
            count
          }
        }
      }
    }
  |}
];

let usePrintersListQuery = () => useQuery(GetPrintersListQuery.definition);

module GetCustomersListQuery = [%graphql
  {|
    query GetCustomersList {
      customer {
        id
        firstName
        lastName
        email
        phoneNumber
        type
      }
    }
  |}
];

let useCustomersListQuery = () => useQuery(GetCustomersListQuery.definition);

module GetOrdersListQuery = [%graphql
  {|
    query GetOrdersList {
      order {
        id
        count
        createdAt
        printedCount
        deliveryCount
        pendingPrintCount
        customer {
          id
          firstName
          lastName
        }
        product {
          id
          label
        }
      }
    }
  |}
];

let useOrdersListQuery = () => useQuery(GetOrdersListQuery.definition);

module GetPrinterDetailsQuery = [%graphql
  {|
    query GetPrinterDetails($id: uuid!) {
      printer_by_pk(id: $id) {
        id
        firstName
        lastName
        printings {
          id
          count
          printedCount
        }
      }
    }
  |}
];

let usePrinterDetailsQuery = printerId =>
  switch (printerId) {
  | Some(id) =>
    useQuery(
      ~variables=GetPrinterDetailsQuery.makeVariables(~id=Js.Json.string(id), ()),
      GetPrinterDetailsQuery.definition,
    )
  | None => useQuery(~skip=true, GetPrinterDetailsQuery.definition)
  };

module GetPrintingDetailsQuery = [%graphql
  {|
    query GetPrintingDetails($id: uuid!) {
      printing_by_pk(id: $id) {
        id
        count
        printedCount
        printedDate
        deliveryDate
      }
    }
  |}
];

let usePrintingDetailsQuery = id =>
  useQuery(
    ~variables=GetPrintingDetailsQuery.makeVariables(~id, ()),
    GetPrintingDetailsQuery.definition,
  );

module GetOrderDetailsQuery = [%graphql
  {|
    query GetOrderDetails($id: uuid!) {
      order_by_pk(id: $id) {
        id
      }
    }
  |}
];

let useOrderDetailsQuery = id =>
  useQuery(
    ~variables=GetOrderDetailsQuery.makeVariables(~id, ()),
    GetOrderDetailsQuery.definition,
  );
