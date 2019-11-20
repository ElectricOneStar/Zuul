#include <iostream> // library
#include <cstring>
#include "Item.h"

using namespace std;

Item::Item(){ // constructor

}
Item::~Item(){ // destuctor
  delete name;
}
char* Item::getName(){ // get name
  return name;
}
void Item::setName(char* n){ // sets name
  name = n;
}
