// Rocelyn Young
// Northwestern University
// CS 211
// Week of April 14, 2025


#include <iostream>
#include <string>

#include "building.h"
#include "buildings.h"
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
cin >> filename;

if (!osmLoadMapFile(filename, xmldoc)) {
    return 0;}

    Nodes object(xmldoc);
    Buildings buildings(xmldoc);
    int num_of_nodes = object.getNumOsmNodes();
    int num_of_buildings = buildings.GetNumOsBuildings();

    cout << "# of nodes: " << num_of_nodes << endl;  
    cout << "# of buildings: " << num_of_buildings<< endl; 
    
    // Initialize looping question
    string command_input;
    cout << "Enter building name (partial or complete), or * to list, or $ to end" << endl;
    getline(cin, command_input);

    // Access vecot of Buildings
    vector<Building> building_vector = buildings.GetOsmBuildings();
    // While input is not $, continue
    while (command_input != "$") {
        // if inputted *, go through building
        if (command_input == "*") {
            for (Building& b : building_vector) {
                cout << b.getID() << ": " << b.getName() << ", " << b.getStreetAddress() << endl;
            }}

        // else, 


        // Ask again
        getline(cin, command_input);
    }

    cout << endl;
    cout << "** Done **" << endl;
    cout << "# of calls to getID(): " << Node::getCallsToGetID()<< endl;
    cout << "# of Nodes created: " << Node::getCreated()<< endl;
    cout << "# of Nodes copied: " << Node::getCopied()<< endl; 
    cout << "# of Nodes copied: " << Node::getCopied()<< endl;    
}