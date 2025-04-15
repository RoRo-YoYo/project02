/*buildings.h*/
//
// A collection of buildings in the Open Street Map.
//
// Rocelyn Young
// Northwestern University
// CS 211
//
// Original author: Prof. Joe Hummel
//

#pragma once 
#include <vector> 

#include "building.h" 
#include "tinyxml2.h" 

using namespace std; 
using namespace tinyxml2;

//
// Keeps track of
// all the buildings in the map
//

class Buildings {
    public:
        vector<Building> osmBuildings;

        //
        // constructor
        //
        // Given an XML document, reads trhoguh the document and
        // stores all the buildings into the vector data member.
        Buildings(XMLDocument& xmldoc);

        //
        // accessors / getters
        //

        int GetNumOsBuildings();
    };    