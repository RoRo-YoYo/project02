#include <iostream>
#include <string>

#include "building.h"
#include "node.h"
#include "nodes.h"
#include "osm.h"
#include "tinyxml2.h"


using namespace std;
using namespace tinyxml2;


int main() {

XMLDocument xmldoc;

cout << "** NU open street map **" << endl;

string filename;

cout << endl;
cout << "Enter map filename>" << endl;


getline(cin, filename);

if (!osmLoadMapFile(filename, xmldoc)) {
    return 0;}

    Nodes object(xmldoc);
    int num_of_nodes = object.getNumOsmNodes();
    
    cout << "# of nodes: " << num_of_nodes << endl;  
    
    cout << endl;
    cout << "** Done **" << endl;
    cout << "# of calls to getID(): " << Node::getCallsToGetID()<< endl;
    cout << "# of Nodes created: " << Node::getCreated()<< endl;
    cout << "# of Nodes copied: " << Node::getCopied()<< endl;    
}