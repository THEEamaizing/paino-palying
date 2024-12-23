include  <iostream>
#include <vector>
#include <string>

using namespace std;

/// @Define structure of an item
struct item{

 int id; 
 string name; 
 double price;

 /// @Displaying items details
 void display() const{
  cout<<"ID:"<<id<<",Name:"<<name<<",Price:$"<<price<<endl;
 }
};

///Fuction prototype
void createitem(vector<item>&items);///FX for creating  new items

void readitems(const vector<item>$items);///FX for read items

void updateitems(vector<item>$items) ///FX for update items

void deleteitems(vector<item>&items); ///  FX for deletion items

int main (){
vector <items>items; ///vector for storing items
int choice; ///variable for storing user items

choice

do {  /* Displaying menu option */

   cout <<"\n--- CRUd operation menu---\n";

   cout <<"1. Create items\n";/// option to create

   cout <<"2.Read items\n";/// option to read

   cout <<"3.---Update items\n";/// Option to update

   cout <<"4.---Delete items\n"; /// option to delete

   cout <<"\nExits\n" /// Option to exits

   cout <<"Enter your choice";///
   cin  >>choice;/// user required to enter his or her choice

 choice
    switch (choice) {

    case 1:
     createitem(items):
    
    break;
    
    case2:
     readitems(items):

    break;
   
    case3:
     updateitems(items):

    break;
 
    case4:
     deleteitems(items):
     break;  

    case5:
     cout <<"Exiting the program.\n"; /// Exiting message
    break;  

    default
    cout <<"Invalid choice. Please try again.\n";/// its handle invalid input
    }

  }while (choice != 5);/// Repeate untill user select exit

   return 0;/// indictating successful execution
}
