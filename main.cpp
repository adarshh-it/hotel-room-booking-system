#include <iostream>
using namespace std;

class Room {
public:
    int roomNo;
    string type;
    float price;
    bool isBooked;

    void display() {
        cout << "Room: " << roomNo
             << " | Type: " << type
             << " | Price: " << price
             << " | Status: " << (isBooked ? "Booked" : "Available")
             << endl;
    }
};

int main() {
    Room rooms[3] = {
        {101, "Single", 1000, false},
        {102, "Double", 1500, false},
        {103, "Deluxe", 2000, false}
    };

    cout << "\n--- Room List ---\n";
    for (int i = 0; i < 3; i++) {
        rooms[i].display();
    }

    return 0;
}