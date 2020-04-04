open Storybook;

let test = () => <div> "test"->React.string </div>;
let materialUi = ((), ()) => {
  MaterialUi.(
    <Paper square=true>
      <Tabs indicatorColor=`Primary textColor=`Primary>
        <Tab label={"Active"->React.string} />
        <Tab label={"Disabled"->React.string} disabled=true />
        <Tab label={"Active"->React.string} />
      </Tabs>
    </Paper>
  );
};
let graphQl = () => <Root><TestGraphql /></Root>

let default = story("Test");
