#include <iostream>
using namespace std;

class Room {
public:
    int roomNo;
    string type;
    float price;
    bool isBooked;
    string customerName;

    void display() {
        cout << "Room: " << roomNo
             << " | Type: " << type
             << " | Price: " << price
             << " | Status: " << (isBooked ? "Booked" : "Available")
             << endl;
    }

    void book(string name) {
        if (isBooked) {
            cout << "Already booked!\n";
        } else {
            isBooked = true;
            customerName = name;
            cout << "Booking successful!\n";
        }
    }
};

int main() {
    Room rooms[3] = {
        {101, "Single", 1000, false, ""},
        {102, "Double", 1500, false, ""},
        {103, "Deluxe", 2000, false, ""}
    };

    int roomNo;
    string name;

    cout << "\n--- Rooms ---\n";
    for (int i = 0; i < 3; i++) {
        rooms[i].display();
    }

    cout << "\nEnter room number to book: ";
    cin >> roomNo;
    cout << "Enter name: ";
    cin >> name;

    for (int i = 0; i < 3; i++) {
        if (rooms[i].roomNo == roomNo) {
            rooms[i].book(name);
        }
    }

    return 0;
}
