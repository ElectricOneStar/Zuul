#ifndef ITEM_H // library. This the item class which contains the name
#define ITEM_H
#include<iostream>
#include<cstring>

using namespace std;

class Item {
 public:
  Item(); // constructor 
  ~Item(); // destructor
  char* getName(); // initialzes functions
  void setName(char* n);
 private:
  char* name = new char[20]; // initializes variables
};
#endif
