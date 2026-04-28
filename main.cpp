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

    void checkout() {
        if (!isBooked) {
            cout << "Room already empty!\n";
        } else {
            isBooked = false;
            customerName = "";
            cout << "Checkout successful!\n";
        }
    }
};

int main() {
    Room rooms[3] = {
        {101, "Single", 1000, false, ""},
        {102, "Double", 1500, false, ""},
        {103, "Deluxe", 2000, false, ""}
    };

    int choice, roomNo;
    string name;

    do {
        cout << "\n1. View Rooms\n2. Book Room\n3. Checkout\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 3; i++) {
                    rooms[i].display();
                }
                break;

            case 2:
                cout << "Enter room number: ";
                cin >> roomNo;
                cout << "Enter name: ";
                cin >> name;

                for (int i = 0; i < 3; i++) {
                    if (rooms[i].roomNo == roomNo) {
                        rooms[i].book(name);
                    }
                }
                break;

            case 3:
                cout << "Enter room number: ";
                cin >> roomNo;

                for (int i = 0; i < 3; i++) {
                    if (rooms[i].roomNo == roomNo) {
                        rooms[i].checkout();
                    }
                }
                break;
        }

    } while (choice != 4);

    return 0;
}