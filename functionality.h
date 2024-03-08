#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "User.h"

using namespace std;

void register_and_book() {
    cout <<magenta<< "Enter your details to book:" << endl;
    string username, phone_num;
    cout << "Enter your name: ";
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
        getline(iss, roomId, ' ');
        getline(iss, type, ' ');
        getline(iss, isAvailableStr, ' ');
        getline(iss, price, ' ');

        if (stoi(roomId) == id) {
            // Update the row if the room ID matches
            if (isAvailableStr == "true") {
                // Room is available, update the status to the user's name
                outFile << roomId << " " << type << " " << username << " " << price << endl;
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
        cout <<blue<< "Room with ID " << id << " is already booked!"<<default << endl;
        remove("temp.txt");
    }
}
