/*buildings.cpp*/
//
// A collection of buildings in the Open Street Map.
//
// Rocelyn Young
// Northwestern University
// CS 211
//
// Original author: Prof. Joe Hummel
//
 
#include <vector> 
#include <cassert> // Include this header for assert
#include "building.h" 
#include "tinyxml2.h" 
#include "buildings.h"
#include "osm.h"
#include "node.h"
#include "nodes.h"

using namespace std; 
using namespace tinyxml2;

/// Constructor
Buildings::Buildings(XMLDocument& xmldoc) {

    XMLElement* osm = xmldoc.FirstChildElement("osm");
    assert(osm != nullptr);

    
    // Start traversal from the first "way" element
    XMLElement* way = osm->FirstChildElement("way");

    while (way != nullptr) {
    // If the way element contains the (key, value) pair (“building”, “university”)
    // then build get name and street address
    if (osmContainsKeyValue(way,"building","university")) {
        string name = osmGetKeyValue(way,"name");
        string streetAddr = osmGetKeyValue(way,"addr:housenumber") + " " + osmGetKeyValue(way,"addr:street");
        
        // Access ID
        const XMLAttribute* attrId = way->FindAttribute("id");
        assert(attrId != nullptr);
        long long id = attrId->Int64Value();

        // Create Building B
        Building B(id, name, streetAddr);

        XMLElement* nd = way->FirstChildElement("nd");
    
        while (nd != nullptr) { 
          const XMLAttribute * ndref = nd->FindAttribute("ref");
          assert(ndref !=nullptr);
          long long id = ndref->Int64Value();
    
          B.add(id);
          
          // advance to next node ref:
          nd = nd->NextSiblingElement("nd");} 
        
          //Once building object B is fully initialized, add B to Buildings vector data member
          osmBuildings.push_back(B);}

          // Move on to the next way
          way = way->NextSiblingElement("way");
        }

    }
/// Get number
int Buildings::GetNumOsBuildings() {
    return osmBuildings.size();}

 /// Get OsmBuildings  
vector<Building> Buildings::GetOsmBuildings() {
    return osmBuildings;}
  
