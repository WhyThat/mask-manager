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

module GetPrinterPrintingsListQuery = [%graphql
  {|
    query GetPrintings($id: uuid!) {
      printer_by_pk(id: $id) {
        id
        printings {
          id
          count
          printedCount
        }
      }
    }
  |}
];

let usePrintingsListQuery = () => useQuery(GetPrinterPrintingsListQuery.definition);

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

let usePrintingDetailsQuery = id => useQuery(~variables=GetPrintingDetailsQuery.makeVariables(~id, ()), GetPrintingDetailsQuery.definition);

module GetOrderDetailsQuery = [%graphql
  {|
    query GetOrderDetails($id: uuid!) {
      order_by_pk(id: $id) {
        id
      }
    }
  |}
];

let useOrderDetailsQuery = id => useQuery(~variables=GetOrderDetailsQuery.makeVariables(~id, ()), GetOrderDetailsQuery.definition);
