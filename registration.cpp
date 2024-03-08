// reegisteratio  in hotel reservation system
#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
    int roomNumber;
};

void registerPerson(Person& person) {
    cout << "Enter name: ";
    getline(cin >> ws, person.name); // reading name with spaces
    cout << "Enter age: ";
    cin >> person.age;
    cout << "Enter room number: ";
    cin >> person.roomNumber;
}
//.........
int main() {
    int totalPersons;
    cout << "Enter total number of persons to register: ";
    cin >> totalPersons;

    Person* persons = new Person[totalPersons]; // Dynamic array to hold persons -

    for (int i = 0; i < totalPersons; ++i) {
        cout << "\nEnter details for person " << i+1 << ":" << endl;
        registerPerson(persons[i]);
    }

    // Display registered persons
    cout << "\nRegistered persons:" << endl;
    for (int i = 0; i < totalPersons; ++i) {
        cout << "Person " << i+1 << ":" << endl;
        cout << "Name: " << persons[i].name << endl;
        cout << "Age: " << persons[i].age << endl;
        cout << "Room Number: " << persons[i].roomNumber << endl;
        cout << endl;
    }

    delete[] persons; // Free dynamically allocated memory

    return 0;
}