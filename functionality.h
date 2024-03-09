#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<cstring>
#include "User.h"

using namespace std;

void register_and_book() {
    cout <<magenta<< "Enter your details to book:" << endl;
    string username, phone_num;
    cout << "Enter your first name: ";
    cin >> username;
    cout << "Enter your phone number: ";
    cin >> phone_num;
    User user(username, phone_num);
    int id;
    cout << "Enter the id of the room you want to book: "<<default;
    cin >> id;

    ifstream inFile("hotelroom.txt");
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open input file" << endl;
        return;
    }

    ofstream outFile("temp.txt");
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open output file" << endl;
        inFile.close();
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string roomId, type, isAvailableStr, price;
        getline(iss, roomId, ',');
        getline(iss, type, ',');
        getline(iss, isAvailableStr, ',');
        getline(iss, price, ',');

        if (stoi(roomId) == id) {
            // Update the row if the room ID matches
            if (isAvailableStr == "true") {
                // Room is available, update the status to the user's name
                outFile << roomId << "," << type << "," << username << "," << price << endl;
                found = true;
            } else {
                // Room is not available, keep the status unchanged
                outFile << line << endl;
            }
          
        } else {
            // Copy the row as it is if the room ID doesn't match
            outFile << line << endl;
        }
    }
    inFile.close();
    outFile.close();

    if (found) {
        // Rename the temporary file to the original filename
        remove("hotelroom.txt");
        rename("temp.txt", "hotelroom.txt");
        cout << magenta<<"Room booked successfully with id of user " << user.getName() <<default << endl;
    } else {
        cout <<blue<< "Room with ID " << id << " is not found or it is already booked!"<<default << endl;
        remove("temp.txt");
    }
}

vector<Room> search_info(string name)
{
   vector<Room> bookedrooms;
    ifstream file("hotelroom.txt");
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            istringstream iss(line);
            string id, type, isAvailableStr, price;
            getline(iss, id, ',');
            getline(iss, type, ',');
            getline(iss, isAvailableStr, ',');
            getline(iss, price, ',');
            if(isAvailableStr==name){
                bookedrooms.push_back(Room(stoi(id), type,stoi(price)));
            }
        }
        file.close();

}

        return bookedrooms;
}
void checkout(string name){
    vector<Room> info=search_info(name);
    if(info.size()==0){
        cout <<red<< "No user found with name " << name << default<<endl;
    }
    else{
         cout << "---------------------------------------------" << endl;
        cout << green<<"ID    " << "Type       " << setw(10)<< "Booked By" <<default<< endl;
        cout << "---------------------------------------------" << endl;
    for (int i = 0; i < info.size(); i++) {
            cout << info[i].getId() << "  ";
            cout << setw(10) << left << info[i].getType();
            cout << setw(10) << right << name << endl;
            
        }
        cout << "---------------------------------------------" << endl;

        ifstream inFile("hotelroom.txt");
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open input file" << endl;
        return;
        }
    
    string username=username;
    int id;
    cout<< "Enter the id of the room you want to checkout: ";
    cin>> id;

    ofstream outFile("temp.txt");
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open output file" << endl;
        inFile.close();
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string roomId, type, isAvailableStr, price;
        getline(iss, roomId, ',');
        getline(iss, type, ',');
        getline(iss, isAvailableStr, ',');
        getline(iss, price, ',');

        if (stoi(roomId) == id) {
            // Update the row if the room ID matches
            if (isAvailableStr == name) {
                // Room is available, update the status to the user's name
                outFile << roomId << "," << type << "," << "true" << "," << price << endl;
                found = true;
            } else {
                // Room is not available, keep the status unchanged
                outFile << line << endl;
            }
          
        } else {
            // Copy the row as it is if the room ID doesn't match
            outFile << line << endl;
        }
    }
    inFile.close();
    outFile.close();

    if (found) {
        // Rename the temporary file to the original filename
        remove("hotelroom.txt");
        rename("temp.txt", "hotelroom.txt");
        cout << magenta<<"Room Checked out successfully for Room id "<<id <<" from " << username <<default << endl;
    } else {
        cout <<blue<< "Room with ID " << id << " is not found!"<<default << endl;
        remove("temp.txt");
    }
   }
  

    }
      


