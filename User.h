#ifndef user_h
#define user_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include<algorithm>
#include <iomanip>

using namespace std;


class User{
protected:
    int id;
    string name, phone;
public:

    static int Nextid;
    User(string name, string phone){
        id =Nextid+1;
        this->name = name;
        this->phone = phone;
    }
   int getId(){
    return id;
   }
   string getName(){
    return name;
   }
    string getPhone(){
    return phone;
   }
    // No need to define destructor unless necessary
};
int User::Nextid =0;
class Room{
protected:
    int room_no,price;
    string type;
    bool isAvailable;

public:
    Room(int room_no, string type,int price, bool isAvailable = true){
        this->room_no = room_no;
        this->price = price;
        this->type = type;
        this->isAvailable = isAvailable;
    }
    int getId() const{
        return room_no;
    }
    int getPrice() const{
        return price;
    }
    string getType() const{
        return type;
    }
    bool getAvailability() const{
        return isAvailable;
    }
};  
pair<int, vector<Room>> countAvailableRooms(const string& filename) {
    int count = 0;
    vector<Room> availableRooms; // Vector to store available rooms
    
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string id, type, isAvailableStr,price;
            getline(iss, id, ' ');
            getline(iss, type, ' ');
            getline(iss, isAvailableStr, ' ');
            getline(iss, price, ' ');
            bool isAvailable = (isAvailableStr == "true");
            if (isAvailable) {
                count++;
                // Create a Room object and add it to the vector of available rooms
                availableRooms.push_back(Room(stoi(id), type,stoi(price)));
            }
        }
        file.close();
    } else {
        cerr << "Internal Server error" << endl;
    }
    
    // Return the count of available rooms and the vector of available rooms
    return make_pair(count, availableRooms);
}

vector<Room> searchRoom(string q){
    int count;
   vector<Room> availableRooms;

    std::cout << "Searching ...." << endl <<endl;
    ifstream file("hotelroom.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
           string type,isAvailable,id,price;
           
           file >> id >> type >> isAvailable >>price;
           if(type==q){
               availableRooms.push_back(Room(stoi(id), type,stoi(price)));
           }
        }
        file.close();
    } else {
        cerr << "Internal Server error" << endl;
    }
    return availableRooms;

    // Implement room search functionality here
    // Open the file, read each line, and search for the room type
}

#endif
