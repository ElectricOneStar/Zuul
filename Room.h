#ifndef ROOM_H
#define ROOM_H
#include <iostream> // libraries
#include <cstring> // This is the room class and it contains the name, description, and room inventory or rinvent
#include <vector>
#include <map>
#include "Item.h"
using namespace std;
class Room{ 
 public:
  Room(); // constuctor
  ~Room(); // destructor
  void AddVector(Item* I); // initalizes functions
  void SetVector(vector<Item*>* v);
  vector<Item*>* GetVector();
  char* GetName();
  void SetName(char* n);
    char* GetDescription();
  void SetDescription(char* d);
  void SetExits(char* d, Room* r);
  Room* GetRoom(char* d);
 private:
  vector<Item*>* rinvent = new vector<Item*>; // initailizes variables
  char* name = new char[20];
  char* description = new char[50];
  map<char*, Room*> exits;
};
#endif
