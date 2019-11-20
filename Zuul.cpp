/*
Zuul by Andrew Thomas 11/19/19 Mr.Galbraith C++ Class Semester 1.
This projects is game where there are rooms that contain items in them. The user can pick and drop items and can go from one room to another by saying go with a cardinal direction. they can also manually quit the game by typing quit. they can type in inventory to get their inventory or type in room informaiton to get the information about the room(Description, items, exits). You can win the game by pick the key from the Janitory room and going to the band room with the chest and dropping the key there.
 */
#include <iostream> // libraries
#include "Room.h"
#include "Item.h"
#include <vector>
#include <cstring>
#include <map>
using namespace std;
bool ItemExistRoom(vector<Room*>* v, char* wordTwo, Room* CurrentRoom); // initailizeing funcitons
bool ItemExistInventory(vector<Item*>* v, char* wordTwo);
//void PrintRoomInventory(Room* CurrentRoom)
//Item* GetItemExistRoom(vector<Room*>* v, char* wordTwo);
//Item* GetItemExistInventory(vector<Item*>* v, char* wordTwo);
void PrintInventory(vector<Item*>* v);
//void PrintExits(Room* CurrentRoom);
int main(){
  char input[20]; // initialzing variables
  char wordOne[20];
  char wordTwo[20];
  int counterOne = 0;
  int counterTwo = 0;
  int counterThree = 0;
  int counterFour = 0;
  int counterFive = 0;
  int id = 0;
  bool WinCondition = false;
  char* North = new char[20]; // directions
    strcpy(North, "North");
      char* East = new char[20];
      strcpy(East, "East");
       char* South = new char[20];
      strcpy(South, "South");
   char* West = new char[20];
  strcpy(West, "West");
  
  vector<Room*>* map = new vector<Room*>;
    vector<Item*>* inventory = new vector<Item*>;
   vector<Item*>* CodingRoomInventory = new vector<Item*>;
   char* name = new char[20]; /// setting the rooms the structure is set room inventory or vector and description and some rooms have items push back to that room inventory vector.
    Room* CodingRoom = new Room; // R1 Coding room
    Room* CurrentRoom = new Room;
    CurrentRoom = CodingRoom;
    (*CodingRoom).SetVector(CodingRoomInventory);
    char* nOne = new char[20];
    char* dOne = new char[50];
    strcpy(nOne, "Coding Room");
    strcpy(dOne, "This room is lined with computers");
    (*CodingRoom).SetName(nOne);
    (*CodingRoom).SetDescription(dOne);
    Item* Mop = new Item;
    strcpy(name, "Mop"); // mop item
    (*Mop).setName(name);
    (*inventory).push_back(Mop);
    // for(int i = 0; i < strlen((*Mop).getName()); i++){
    //cout << (*Mop).getName()[i];
    //}
    //cout << endl;
     char* nametwo = new char[20];
    //  char name[20];
     Item* BubbleGum = new Item; // bubble gum item
    strcpy(nametwo, "BubbleGum"); 
    (*BubbleGum).setName(nametwo);
    //for(int i = 0; i < strlen((*BubbleGum).getName()); i++){
    //cout << (*BubbleGum).getName()[i];
    //}
    //cout << endl;
    (*inventory).push_back(BubbleGum);
    char* namethree = new char[20];
        Item* Test = new Item;
	strcpy(namethree, "Test"); // test item
    (*Test).setName(namethree);
    // for(int i = 0; i < strlen((*Test).getName()); i++){
    //cout << (*Test).getName()[i];
    //}
    //cout << endl;
    (*CodingRoomInventory).push_back(Test);
    vector<Item*>* GymRoomInventory = new vector<Item*>;
    Room* Gym = new Room; // R2 Gym
    //  CurrentRoom = Gym;
    (*Gym).SetVector(GymRoomInventory);
   char* nTwo = new char[20];
    char* dTwo = new char[50];
    strcpy(nTwo, "Gym");
    strcpy(dTwo, "There are some students shooting hoops");
    (*Gym).SetName(nTwo);
    (*Gym).SetDescription(dTwo);
    char* namefour = new char[20];
    Item* Basketball = new Item; // basketball item 
     strcpy(namefour, "Basketball");
    (*Basketball).setName(namefour);
    //for(int i = 0; i < strlen((*Basketball).getName()); i++){
    // cout << (*Basketball).getName()[i];
    //}
    //cout << endl;
    (*GymRoomInventory).push_back(Basketball);
    //FishBowl
        vector<Item*>* FishBowlRoomInventory = new vector<Item*>;
        Room* FishBowl = new Room; // R3 FishBowl
	//	CurrentRoom = FishBowl;
    (*FishBowl).SetVector(FishBowlRoomInventory);
   char* nThree = new char[20];
    char* dThree = new char[50];
    strcpy(nThree, "Fish Bowl");
    strcpy(dThree, "There are some kids getting tutoring help");
    (*FishBowl).SetName(nThree);
    (*FishBowl).SetDescription(dThree);
    char* namefive = new char[20];
    Item* Homework = new Item; // homework item
     strcpy(namefive, "Homework");
    (*Homework).setName(namefive);
    // for(int i = 0; i < strlen((*Homework).getName()); i++){
    // cout << (*Homework).getName()[i];
    //}
    //cout << endl;
    (*FishBowlRoomInventory).push_back(Homework);
        vector<Item*>* OutsideRoomInventory = new vector<Item*>;
        Room* Outside = new Room; // R4 Outside
	//CurrentRoom = Outside;
    (*Outside).SetVector(OutsideRoomInventory);
   char* nFour = new char[20];
    char* dFour = new char[50];
    strcpy(nFour, "Outside");
    strcpy(dFour, "The birds are singing utop the trees");
    (*Outside).SetName(nFour);
    (*Outside).SetDescription(dFour);
    char* namesix = new char[20];
    Item* Stick = new Item; // stick item
     strcpy(namesix, "Stick");
    (*Stick).setName(namesix);
    // for(int i = 0; i < strlen((*Stick).getName()); i++){
    // cout << (*Stick).getName()[i];
    //}
    //cout << endl;
    (*OutsideRoomInventory).push_back(Stick);
        vector<Item*>* JanitoryRoomInventory = new vector<Item*>;
        Room* JanitoryRoom = new Room; // R5 Janitory Room
	//CurrentRoom = JanitoryRoom;
    (*JanitoryRoom).SetVector(JanitoryRoomInventory);
   char* nFive = new char[20];
    char* dFive = new char[50];
    strcpy(nFive, "Janitory Room");
    strcpy(dFive, "It smells and it is dark");
    (*JanitoryRoom).SetName(nFive);
    (*JanitoryRoom).SetDescription(dFive);
    char* nameseven = new char[20];
    Item* Key = new Item; // key item
     strcpy(nameseven, "Key");
    (*Key).setName(nameseven);
    //for(int i = 0; i < strlen((*Key).getName()); i++){
    // cout << (*Key).getName()[i];
    // }
    //cout << endl;
    (*JanitoryRoomInventory).push_back(Key);
    //band
    vector<Item*>* BandRoomInventory = new vector<Item*>;
    Room* BandRoom = new Room; // R6 Band Room
    //CurrentRoom = BandRoom;
    (*BandRoom).SetVector(BandRoomInventory);
   char* nSix = new char[20];
    char* dSix = new char[50];
    strcpy(nSix, "Band Room");
    strcpy(dSix, "The band kids are playing great music");
    (*BandRoom).SetName(nSix);
    (*BandRoom).SetDescription(dSix);
    char* nameeight = new char[20];
    Item* Chest = new Item; // creates chest
     strcpy(nameeight, "Chest");
    (*Chest).setName(nameeight);
    //for(int i = 0; i < strlen((*Chest).getName()); i++){
    //cout << (*Chest).getName()[i];
    //}
    //cout << endl;
    (*BandRoomInventory).push_back(Chest);
        vector<Item*>* ArtRoomInventory = new vector<Item*>;
    Room* ArtRoom = new Room; // R7 Art Room
    // CurrentRoom = ArtRoom;
    (*ArtRoom).SetVector(ArtRoomInventory);
   char* nSeven = new char[20];
    char* dSeven = new char[50];
    strcpy(nSeven, "Art Room");
    strcpy(dSeven, "The room is scatted with different color paint");
    (*ArtRoom).SetName(nSeven);
    (*ArtRoom).SetDescription(dSeven);
       vector<Item*>* HistoryRoomInventory = new vector<Item*>;
    Room* HistoryRoom = new Room; // R8 History Room
    // CurrentRoom = HistoryRoom;
    (*HistoryRoom).SetVector(HistoryRoomInventory);
   char* nEight = new char[20];
    char* dEight = new char[50];
    strcpy(nEight, "History Room");
    strcpy(dEight, "There are no students in the room");
    (*HistoryRoom).SetName(nEight);
    (*HistoryRoom).SetDescription(dEight);
       vector<Item*>* ChemistryRoomInventory = new vector<Item*>;
    Room* ChemistryRoom = new Room; // R9 Chemistry Room
    //CurrentRoom = ChemistryRoom;
    (*ChemistryRoom).SetVector(ChemistryRoomInventory);
   char* nNine = new char[20];
    char* dNine = new char[50];
    strcpy(nNine, "Chemistry Room");
    strcpy(dNine, "Students are working on a titration lab");
    (*ChemistryRoom).SetName(nNine);
    (*ChemistryRoom).SetDescription(dNine);
       vector<Item*>* PhysicsRoomInventory = new vector<Item*>;
    Room* PhysicsRoom = new Room; // R10 Physics Room
    //CurrentRoom = PhysicsRoom;
    (*PhysicsRoom).SetVector(PhysicsRoomInventory);
   char* nTen = new char[20];
    char* dTen = new char[50];
    strcpy(nTen, "Physics Room");
    strcpy(dTen, "Mr.Schilling greets you. He is grading some tests");
    (*PhysicsRoom).SetName(nTen);
    (*PhysicsRoom).SetDescription(dTen);
       vector<Item*>* BiologyRoomInventory = new vector<Item*>;
    Room* BiologyRoom = new Room; // R11 Biology Room
    // CurrentRoom = BiologyRoom;
    (*BiologyRoom).SetVector(BiologyRoomInventory);
   char* nEleven = new char[20];
    char* dEleven = new char[50];
    strcpy(nEleven, "Biology Room");
    strcpy(dEleven, "It smells like something died");
    (*BiologyRoom).SetName(nEleven);
    (*BiologyRoom).SetDescription(dEleven);
       vector<Item*>* LiteratureRoomInventory = new vector<Item*>;
    Room* LiteratureRoom = new Room; // R12 Literature Room
    //CurrentRoom = LiteratureRoom;
    (*LiteratureRoom).SetVector(LiteratureRoomInventory);
   char* nTweleve = new char[20];
    char* dTweleve = new char[50];
    strcpy(nTweleve, "Literature Room");
    strcpy(dTweleve, "The students are quiety reading");
    (*LiteratureRoom).SetName(nTweleve);
    (*LiteratureRoom).SetDescription(dTweleve);
       vector<Item*>* ATRoomInventory = new vector<Item*>;
    Room* ATRoom = new Room; // R13 // AT
    //CurrentRoom = ATRoom;
    (*ATRoom).SetVector(ATRoomInventory);
   char* nThirteen = new char[20];
    char* dThirteen = new char[50];
    strcpy(nThirteen, "AT");
    strcpy(dThirteen, "There are kids who are working on homework");
    (*ATRoom).SetName(nThirteen);
    (*ATRoom).SetDescription(dThirteen);
       vector<Item*>* MainOfficeRoomInventory = new vector<Item*>;
    Room* MainOfficeRoom = new Room; // R14 Main office
    //CurrentRoom = MainOfficeRoom;
    (*MainOfficeRoom).SetVector(MainOfficeRoomInventory);
   char* nFourteen = new char[20];
    char* dFourteen = new char[50];
    strcpy(nFourteen, "Main Office");
    strcpy(dFourteen, "The woman at the counter is busy");
    (*MainOfficeRoom).SetName(nFourteen);
    (*MainOfficeRoom).SetDescription(dFourteen);
       vector<Item*>* AttendanceOfficeRoomInventory = new vector<Item*>;
    Room* AttendanceOfficeRoom = new Room; // R15 Attendance Office
    //CurrentRoom = AttendanceOfficeRoom;
    (*AttendanceOfficeRoom).SetVector(AttendanceOfficeRoomInventory);
   char* nFifteen = new char[20];
    char* dFifteen = new char[50];
    strcpy(nFifteen, "Attendance Office");
    strcpy(dFifteen, "Students are filling out attendance forms");
    (*AttendanceOfficeRoom).SetName(nFifteen); 
    (*AttendanceOfficeRoom).SetDescription(dFifteen);
    (*CodingRoom).SetExits(East, Gym);     // setting the exits of each room (updates the hashmap in each room)
    (*CodingRoom).SetExits(South, BandRoom);
    (*Gym).SetExits(West, CodingRoom);
     (*Gym).SetExits(South, ArtRoom);
       (*Gym).SetExits(East, FishBowl);
    (*FishBowl).SetExits(West, Gym);
    (*FishBowl).SetExits(South, HistoryRoom);
    (*FishBowl).SetExits(East, Outside);
    (*Outside).SetExits(West, FishBowl);
    (*Outside).SetExits(South, ChemistryRoom);
    (*Outside).SetExits(East, JanitoryRoom);
    (*JanitoryRoom).SetExits(West, Outside);
    (*JanitoryRoom).SetExits(South, PhysicsRoom);
    (*BandRoom).SetExits(North, CodingRoom);
    (*BandRoom).SetExits(East, ArtRoom);
        (*BandRoom).SetExits(South, BiologyRoom);
	(*ArtRoom).SetExits(West, BandRoom);
    (*ArtRoom).SetExits(North, Gym);
    (*ArtRoom).SetExits(East, HistoryRoom);
    (*ArtRoom).SetExits(South, LiteratureRoom);
    (*HistoryRoom).SetExits(North, FishBowl);
    (*HistoryRoom).SetExits(West, ArtRoom);
    (*HistoryRoom).SetExits(East, ChemistryRoom);
    (*HistoryRoom).SetExits(South, ATRoom);
    (*ChemistryRoom).SetExits(West, HistoryRoom);
    (*ChemistryRoom).SetExits(North, Outside);
    (*ChemistryRoom).SetExits(East, PhysicsRoom);
    (*ChemistryRoom).SetExits(South, MainOfficeRoom);
    (*PhysicsRoom).SetExits(North, JanitoryRoom);
    (*PhysicsRoom).SetExits(West, ChemistryRoom);
    (*PhysicsRoom).SetExits(South, AttendanceOfficeRoom);
    (*BiologyRoom).SetExits(North, BandRoom);
    (*BiologyRoom).SetExits(East, LiteratureRoom);
    (*LiteratureRoom).SetExits(North, ArtRoom);
    (*LiteratureRoom).SetExits(West, BiologyRoom);
    (*LiteratureRoom).SetExits(East, ATRoom);
    (*ATRoom).SetExits(North, HistoryRoom);
    (*ATRoom).SetExits(East, MainOfficeRoom);
    (*ATRoom).SetExits(West, LiteratureRoom);
    (*MainOfficeRoom).SetExits(North, ChemistryRoom);
    (*MainOfficeRoom).SetExits(West, ATRoom);
    (*MainOfficeRoom).SetExits(East, AttendanceOfficeRoom);
    (*AttendanceOfficeRoom).SetExits(North, PhysicsRoom);
    (*AttendanceOfficeRoom).SetExits(West, MainOfficeRoom);
    cout << "Welcome to Zuul. Figure out how to open the chest." << endl; // intro plus initial room info
          	cout << "Your are in ";
	for(int i = 0; i < strlen((*CurrentRoom).GetName()); i++){
	  cout << (*CurrentRoom).GetName()[i];
	}
	cout << endl;
	for(int i = 0; i < strlen((*CurrentRoom).GetDescription()); i++){
	  cout << (*CurrentRoom).GetDescription()[i];
	}
	cout << endl;
	cout << "Exits: ";
	if((*CurrentRoom).GetRoom(North) != 0){
	  cout << "North ";
	}
	if((*CurrentRoom).GetRoom(East) != 0){
	  cout << "East ";
	}
	if((*CurrentRoom).GetRoom(South) != 0){
	  cout << "South ";
	}
	if((*CurrentRoom).GetRoom(West) != 0){
	  cout << "West ";
	}
	

	cout << endl;
	cout << "Items In this room: ";
	PrintInventory((*CurrentRoom).GetVector());


	do{ // do while loop with win condiiton
	  int counterOne = 0; // reset counters
  int counterTwo = 0;
  int counterThree = 0;
  int counterFour = 0;
   int counterFive = 0;
  int id = 0;


  cout << "Please enter a command(pick item, drop item, inventory, room information, go North/East/South/West, quit)" << endl; // pick command
  cin.get(input, 20); // gets command
  cin.clear();
  cin.ignore();
  for(int i = 0; i < strlen(input); i++){ // parce the input
    if(counterOne == 0 && input[i] != ' '){
      //cout << "h1" << endl;
      wordOne[i] = input[i];
    }
    if(counterOne == 1 && input[i] != ' '){
      //cout << "h2" << endl;
      wordTwo[counterTwo] = input[i];
      counterFour++;
      counterTwo++;
    }
    if(input[i] == ' '){
      //cout << "h3" << endl;
        wordOne[i] = '\0';
      counterOne++;
    }
  }
  if(counterOne == 0){
   wordOne[strlen(input)] = '\0';
  }
  
  wordTwo[counterFour] = '\0';
  // cout << "Input: ";
  //  for(int i = 0; i < strlen(input); i++){
  //  cout << input[i];
  // }
  //cout << endl;
  //cout << "WordOne: ";
  //for(int i = 0; i < strlen(wordOne); i++){
  //   cout << wordOne[i];
  // }
  // cout << endl;
  //cout << "WordTwo: ";
  // for(int i = 0; i < strlen(wordTwo); i++){
  //   cout << wordTwo[i];
  // }
  // cout << endl;
  if(strcmp(wordOne, "drop") == 0 && ItemExistInventory(inventory, wordTwo)){ // drop item
      cout << "dropped" << endl;
      //char* temp = new Item[20];
      Item* temp = new Item;
      for(vector<Item*>::iterator it = (*inventory).begin(); it !=(*inventory).end(); it++){
    if(strcmp((*(*it)).getName(), wordTwo) == 0){
      id = counterThree;
      temp = (*it);
    }
    counterThree++;
	}
         
      (*inventory).erase(id + (*inventory).begin()); // remove the item from inventory
      (*(*CurrentRoom).GetVector()).push_back(temp); // add it to the room inventory
    }
  else if(strcmp(wordOne, "pick") == 0 && ItemExistRoom(map, wordTwo, CurrentRoom)){ // pick item
      cout << "picked" << endl;
           Item* temp = new Item;
	   for(vector<Item*>::iterator it = (*(*CurrentRoom).GetVector()).begin(); it !=(*(*CurrentRoom).GetVector()).end(); it++){
    if(strcmp((*(*it)).getName(), wordTwo) == 0){
      id = counterThree;
      temp = (*it);
    }
    counterFive++;
	   }
         
	   (*(*CurrentRoom).GetVector()).erase(id + (*(*CurrentRoom).GetVector()).begin()); // delete from room inventory
	   (*inventory).push_back(temp); // add item to the inventory
      //Item* temp = new Item;
      //(*temp).setName(wordTwo);
      //(*inventory).push_back(temp)
      
    }
    
  else if(strcmp(wordOne, "room") == 0 && strcmp(wordTwo, "information") == 0){ // room inventory
      	cout << "Your are in ";
	for(int i = 0; i < strlen((*CurrentRoom).GetName()); i++){
	  cout << (*CurrentRoom).GetName()[i]; // name of the room
	}
	cout << endl;
	for(int i = 0; i < strlen((*CurrentRoom).GetDescription()); i++){
	  cout << (*CurrentRoom).GetDescription()[i]; // description
	}
	cout << endl;
	cout << "Exits: "; // exits with the hasmap
	if((*CurrentRoom).GetRoom(North) != 0){
	  cout << "North ";
	}
	if((*CurrentRoom).GetRoom(East) != 0){
	  cout << "East ";
	}
	if((*CurrentRoom).GetRoom(South) != 0){
	  cout << "South ";
	}
	if((*CurrentRoom).GetRoom(West) != 0){
	  cout << "West ";
	}


	cout << endl;
	cout << "Items In this room: ";
	PrintInventory((*CurrentRoom).GetVector()); // prints room inventory

      }
    //else if(strcmp(wordOne, "exits") == 0){
      //cout << "Items In this room: " << endl;
      //PrintExits(CurrentRoom);
      //}

	
  else if(strcmp(wordOne, "go") == 0){ // go direction
      if(strcmp(wordTwo, "North") == 0 || strcmp(wordTwo, "East") == 0 || strcmp(wordTwo, "South") == 0 || strcmp(wordTwo, "West") == 0){
	//cout << "direction" << endl;
	if(strcmp(wordTwo, "North") == 0){
	  if((*CurrentRoom).GetRoom(North) != 0){ // sets current room and checks if there is a room in that direction NORTH
	  CurrentRoom = (*CurrentRoom).GetRoom(North);
	  }
	  else{
	  cout << "There is no room North from your curernt room" << endl;
	  //break;
	}
	}
	//	else{
	//cout << "There is no room North from your curernt room" << endl;
	//}
	if(strcmp(wordTwo, "East") == 0){ // EAST
	  //CurrentRoom = (*CurrentRoom).GetRoom(East);
	  	  if((*CurrentRoom).GetRoom(East) != 0){
		    CurrentRoom = (*CurrentRoom).GetRoom(East);
	  }
	  else{
	  cout << "There is no room East from your curernt room" << endl;
	  //break;
	  }

	}
	//else{
	//cout << "There is no room East from your curernt room" << endl;
	//}
	if(strcmp(wordTwo, "South") == 0 ){ // SOUTH
	  	  if((*CurrentRoom).GetRoom(South) != 0){
	  CurrentRoom = (*CurrentRoom).GetRoom(South);
	  }
	  else{
	  cout << "There is no room South from your curernt room" << endl;
	  //break;
	  }

	  //CurrentRoom = (*CurrentRoom).GetRoom(South);
	}
	//else{
	//cout << "There is no room South from your curernt room" << endl;
	//}
	if(strcmp(wordTwo, "West") == 0){ //WEST
	  if((*CurrentRoom).GetRoom(West) != 0){
	  CurrentRoom = (*CurrentRoom).GetRoom(West);
	  }
	  else{
	  cout << "There is no room West from your curernt room" << endl;
	  //break;
	  }

	  //CurrentRoom = (*CurrentRoom).GetRoom(West);
	}
	//else{
	//cout << "There is no room West from your curernt room" << endl;
	//}
	//if(){
	//}

	cout << "Your are in ";
	for(int i = 0; i < strlen((*CurrentRoom).GetName()); i++){
	  cout << (*CurrentRoom).GetName()[i]; // room name 
	}
	cout << endl;
	for(int i = 0; i < strlen((*CurrentRoom).GetDescription()); i++){
	  cout << (*CurrentRoom).GetDescription()[i]; // room description
	}
	cout << endl;
	cout << "Exits: "; //exits with hashmap
	if((*CurrentRoom).GetRoom(North) != 0){
	  cout << "North ";
	}
	if((*CurrentRoom).GetRoom(East) != 0){
	  cout << "East ";
	}
	if((*CurrentRoom).GetRoom(South) != 0){
	  cout << "South ";
	}
	if((*CurrentRoom).GetRoom(West) != 0){
	  cout << "West ";
	}


	cout << endl;
	cout << "Items In this room: "; // prints the items in the room
	PrintInventory((*CurrentRoom).GetVector());
      }
      
    }
  else if(strcmp(wordOne, "quit") == 0){ // if quit return 0
	  return 0;
	}

  else if(strcmp(wordOne, "inventory") == 0){ // prints the room inventory useing the function
      cout << "Items in inventory: ";
      PrintInventory(inventory);
      // cout << "Room" << endl;
      //PrintInventory(roomInventory);
    }
    else{
      cout << "Sorry command not recognized" << endl; // invalid command
    } 
    // else if(strcmp(wordOne, "inventory") == 0){
     //	  return 0;
    //}
  if(CurrentRoom == BandRoom && ItemExistRoom(map, (*Chest).getName(), BandRoom) && ItemExistRoom(map, (*Key).getName(), BandRoom)){ // key dropped in band room with chest
      WinCondition = true;
      
    }
    // vector<Room*>* map = new vector<Room*>;
  //vector<char*>* inventory = new vector<char*>;
    }
	while(WinCondition == false); // loop until win
	cout << "Congratulations you Win. Your treasue is knowledge. Please play again." << endl; // win condition statement
    return 0;
}
bool ItemExistRoom(vector<Room*>* v, char* wordTwo, Room* CurrentRoom){ // checks if item exits in room
  //return true;
    for(vector<Item*>::iterator it = (*(*CurrentRoom).GetVector()).begin(); it !=(*(*CurrentRoom).GetVector()).end(); it++){
      if(strcmp((*(*it)).getName(), wordTwo) == 0){ // if item is the same as any item in room inventory
      return true;
    }
    }
  return false;

}

bool ItemExistInventory(vector<Item*>* v, char* wordTwo){ // checks if item exists in inventory
  /*
  for(vector<Item*>::iterator it = ((*CurrentRoom).GetVector()).begin(); it !=((*CurrentRoom).GetVector()).end(); it++){
    if(strcmp((*(*it)).getName(), wordTwo) == 0){
      return true;
    }
    }
  return false;
  */
      for(vector<Item*>::iterator it = (*v).begin(); it !=(*v).end(); it++){
	if(strcmp((*(*it)).getName(), wordTwo) == 0){ // checks if item matches any item in the inventory
      return true;
    }
    }
  return false;

  
}
/*
Item* GetItemExistRoom(vector<Room*>* v, char* wordTwo){
  return true;
}
Item* GetItemExistInventory(vector<Item*>* v, char* wordTwo){
  return true;
}
*/
void PrintInventory(vector<Item*>* v){
  for(vector<Item*>::iterator it = (*v).begin(); it !=(*v).end(); it++){
      for(int i = 0; i < strlen((*(*it)).getName()); i++){
	cout << (*(*it)).getName()[i]; // name of item
    }
      cout << " "; // goes through each item in the inventory(room or user)
  }
  cout << endl;
}
//void PrintExits(Room* CurrentRoom){
// cout << "Exits: " << endl;
//}
  


