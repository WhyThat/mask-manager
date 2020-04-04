open ApolloHooks;

module AddPrinterMutation = [%graphql
  {|
    mutation AddPrinter(
      $firstName: String!,
      $lastName: String!,
      $email: String!,
      $phoneNumber: String!,
      $printerCount: Int!
    ) {
      insert_printer(objects: {
        firstName: $firstName,
        lastName: $lastName,
        email: $email,
        phoneNumber: $phoneNumber,
        printerCount: $printerCount,
      }) {
        returning {
          id
          firstName
          lastName
          email
          phoneNumber
          printerCount
        }
      }
    }
  |}
];

let useAddPrinterMutation = () => useMutation(AddPrinterMutation.definition);

module AddCustomerMutation = [%graphql
  {|
    mutation AddCustomer(
      $firstName: String!,
      $lastName: String!,
      $email: String!,
      $phoneNumber: String!,
      $type: String!
    ) {
      insert_customer(objects: {
        firstName: $firstName,
        lastName: $lastName,
        email: $email,
        phoneNumber: $phoneNumber,
        type: $type,
      }) {
        returning {
          id
          firstName
          lastName
          email
          phoneNumber
          type
        }
      }
    }
  |}
];

let useAddCustomerMutation = () => useMutation(AddCustomerMutation.definition);

module AddOrderMutation = [%graphql
  {|
    mutation AddOrder(
      $count: Int!,
    ) {
      insert_order(objects: {
        count: $count,
      }) {
        returning {
          id
          count
          product {
            id
            label
          }
        }
      }
    }
  |}
];

let useAddOrderMutation = () => useMutation(AddOrderMutation.definition);

module AddPrintingMutation = [%graphql
  {|
    mutation AddPrinting(
      $count: Int!,
      $orderId: uuid!,
      $printerId: uuid!,
    ) {
      insert_printing(objects: {
        count: $count,
        printerId: $printerId,
        orderId: $orderId,
      }) {
        returning {
          id
          count
        }
      }
    }
  |}
];

let useAddPrintingMutation = () => useMutation(AddPrintingMutation.definition);

module UpdatePrintingMutation = [%graphql
  {|
    mutation UpdatePrinting(
      $printingId: uuid!,
      $count: Int!,
      $printedCount: Int!,
      $printedDate: timestamptz,
      $deliveryDate: timestamptz,
    ) {
      update_printing(
        where: { id: { _eq: $printingId } },
        _set: { printedCount: $printedCount, count: $count, printedDate: $printedDate, deliveryDate: $deliveryDate }
      ) {
        returning {
          id
          count
        }
      }
    }
  |}
];

let useUpdatePrintingMutation = () => useMutation(UpdatePrintingMutation.definition);

module DeletePrintingMutation = [%graphql
  {|
    mutation DeletePrinting($printingId: uuid!) {
      delete_printing(where: { id: { _eq: $printingId } }) {
        returning {
          id
        }
      }
    }
  |}
];

let useDeletePrintingMutation = () => useMutation(DeletePrintingMutation.definition);
