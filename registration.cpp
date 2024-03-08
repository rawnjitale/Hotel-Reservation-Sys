#include "User.h"
#include "style.h"
#include "functionality.h"
using namespace std;
#define dot "_____" 
int main(){
     cout <<magenta <<dot<<dot<<dot<<dot<<dot<<dot<<dot << endl;
    cout <<setw(30) <<"| Available Rooms Count |" << endl;
    cout <<dot<<dot<<dot<<dot<<dot<<dot<<dot << endl;
    cout <<setw(20)<< countAvailableRooms("hotelroom.txt").first << endl;
    cout <<dot<<dot<<dot<<dot<<dot<<dot<<dot << default<< endl;

    // search room 
    cout << endl<< endl<< endl ;
    string query;
    int response;
   
    cout<< "What do you want to do ? : " <<endl;
    cout << "1. Search Room" << endl;
    cout << "2. Book Room" << endl;
    cout << "3. Checkout" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice : " << endl;
    cin>> response;
        // =========if response is 1 then search room =========

        if(response==1){
        //search room function 
        cout << yellow<<"We have following room types: " << endl;
        cout << setw(10)<<"Single" << endl;
        cout << setw(10)<<"Double" << endl;
        cout << setw(10)<<"Deluxe" << endl;
        cout << setw(10)<<"Suite" << endl;
        cout << setw(10)<<"Family" << endl;  
        cout << setw(10)<<"Enter room type : " <<default<< endl;
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
// register_and_book()
 
    
    // book room 

    //checkoutfunctionality

    return 0;
}

