#include <iostream> // libraries
#include "Room.h"
//#include "Item.h"
#include <cstring>
#include <vector>
#include <map>
using namespace std;
Room::Room(){ // constuctor
  // description = newDescription;
  
} 
Room::~Room(){ // destuctor
  // description = newDescription;
  delete rinvent;
  delete name;
  delete description;
}

//char[]* Room::getdescrtion
void Room::AddVector(Item* I){ // adds item to the room inventory
  (*rinvent).push_back(I);
}
void Room::SetVector(vector<Item*>* v){ // sets room inventory 
  rinvent = v;
}
vector<Item*>* Room::GetVector(){ // gets room inventory
  return rinvent;
}
char* Room::GetName(){ // gets name
  return name;
}
void Room::SetName(char* n){ // sets name
  name = n;
}
char* Room::GetDescription(){ // gets description
  return description;
}
void Room::SetDescription(char* d){ // sets description
  description = d;
}
void Room::SetExits(char* d, Room* r){ // sets exits
  exits[d] = r;  
}
Room* Room::GetRoom(char* d){ // get the room with the direciton
  return exits[d];
}

