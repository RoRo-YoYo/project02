/*building.cpp*/

//
// A building in the Open Street Map.
// 
// Prof. Joe Hummel
// Northwestern University
// CS 211
// 

#include "building.h"

using namespace std;


//
// constructor
//
Building::Building(long long id, string name, string streetAddr)
  : ID(id), Name(name), StreetAddress(streetAddr)
{
  // vector is default initialized by its constructor
}

//
// adds the given nodeid to the end of the vector.
//
void Building::add(long long nodeid)
{
  this->NodeIDs.push_back(nodeid);
}

long long Building::getID() {
  return ID;}

string Building::getName() {
  return Name;
}

string Building::getStreetAddress() {
  return StreetAddress;}

vector<long long>  Building::getNodeIDs() {
  return NodeIDs;
}

