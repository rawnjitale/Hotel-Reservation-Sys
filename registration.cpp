#include "User.h"
#include "style.h"
#include "functionality.h"
using namespace std;
#define dot "_____" 
int main(){
    art();
     cout << setw(100) << setfill('_') << "" << endl;
    cout << setfill(' ');

    // Print the section header
    cout << setw(40) << magenta << "| Available Rooms Count |" << default << endl;

    // Print the middle line
    cout<< setw(40) << setfill('_')<< endl;

    // Print the available rooms count
    std::cout << std::setfill(' ');
    cout << setw(45) << countAvailableRooms("hotelroom.txt").first << endl;

    // Print the bottom line
    std::cout << std::setfill('_');
    cout << setw(100) << setfill('_') << "" << endl;
    // search room 
    cout << endl<< endl<< endl ;
    string query;
    int response;
   
    cout<< "What do you want to do ? : " <<endl;
    cout << "1. Search Room" << endl;
    cout << "2. Book Room" << endl;
    cout << "3. Search Info" << endl;
    cout<< "4. Checkout"<<endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice : " << endl;
    cin>> response;
        // =========if response is 1 then search room =========

        if(response==1){
        std::cout << std::setfill(' ');
        //search room function 
        cout << yellow<<"We have following room types: " << endl;
        cout << setw(45)<<"Single" << endl;
        cout << setw(45)<<"Double" << endl;
        cout << setw(45)<<"Deluxe" << endl;
        cout << setw(45)<<"Suite" << endl;
        cout << setw(45)<<"Family" << endl;  
        cout << setw(45)<<"Enter room type : " <<default<< endl;
        cin >> query;
        
        vector<Room> availableRooms=searchRoom(query);
       cout << "Available rooms of type " << query << " are: " << endl;
        cout << "---------------------------------------------" << endl;
        cout << green<<"ID    " << "Type       " << setw(10)<<"Price(NRS)" <<default<< endl;
        cout << "---------------------------------------------" << endl;
        if(availableRooms.size()==0){
            cout << "Oh looks like we are out of rooms for your "<<" try other room types "<< endl;
        }

        else{

        for (int i = 0; i < availableRooms.size(); i++) {
            cout << availableRooms[i].getId() << "  ";
            cout << setw(10) << left << availableRooms[i].getType();
            cout << setw(10) << right << availableRooms[i].getPrice() << endl;
            
        }
        cout << "---------------------------------------------" << endl;
        cout<<green<<"Do you want to book the room (Y/N)? : "<<default<<endl;
   
 char res;
    cin>>res;
    if(res=='Y' || res=='y'){
    register_and_book();
    
    }
    }
    
        }

// if user enteres 2 then book room by registering the user
if(response==2){
    register_and_book();
}

    
// search for information of user 
if(response==3){
    string query;
    cout<< "Enter the firstname of user you want to search info: "<< endl;
    cin >> query;
    vector<Room> info=search_info(query);
    if(info.size()==0){
        cout <<red<< "No user found with name " << query << default<<endl;

        return 0;
    }
       cout << "---------------------------------------------" << endl;
        cout << green<<"ID    " << "Type       " << setw(10)<< "Booked By" <<default<< endl;
        cout << "---------------------------------------------" << endl;
    for (int i = 0; i < info.size(); i++) {
            cout << info[i].getId() << "  ";
            cout << setw(10) << left << info[i].getType();
            cout << setw(10) << right << query << endl;
            
        }
        cout << "---------------------------------------------" << endl << endl;

}
if(response==4){
    // checkoutFunctionality
    string name;
    int id;
      cout<< blue<< "Your Name: "<< default<< endl;
    cin >> name;                                            
  
    checkout(name);
}


if(response==5){

cout<< "Thank you for vising us "<< endl;
    return 0;
}
    return 0;
}
