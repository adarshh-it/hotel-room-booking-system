#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Room {
public:
    int roomNo;
    string type;
    float price;
    bool isBooked;
    string customerName;
};

// Load data
void loadFromFile(Room rooms[], int size) {
    ifstream file("rooms.txt");
    if (!file) return;

    for (int i = 0; i < size; i++) {
        file >> rooms[i].roomNo
             >> rooms[i].type
             >> rooms[i].price
             >> rooms[i].isBooked
             >> rooms[i].customerName;
    }
}

// Save data
void saveToFile(Room rooms[], int size) {
    ofstream file("rooms.txt");
    for (int i = 0; i < size; i++) {
        file << rooms[i].roomNo << " "
             << rooms[i].type << " "
             << rooms[i].price << " "
             << rooms[i].isBooked << " "
             << rooms[i].customerName << endl;
    }
}

// Login
bool login() {
    string user, pass, u, p;
    cout << "\n===== LOGIN =====\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    ifstream file("users.txt");

    while (file >> u >> p) {
        if (u == user && p == pass) {
            cout << "Login successful!\n";
            return true;
        }
    }

    cout << "Invalid login!\n";
    return false;
}

// Display rooms
void displayRooms(Room rooms[], int size) {
    cout << "\n----------------------------------------\n";
    cout << left << setw(10) << "Room"
         << setw(12) << "Type"
         << setw(10) << "Price"
         << setw(12) << "Status" << endl;
    cout << "----------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(10) << rooms[i].roomNo
             << setw(12) << rooms[i].type
             << setw(10) << rooms[i].price
             << setw(12) << (rooms[i].isBooked ? "Booked" : "Available")
             << endl;
    }
}

// Book room
void bookRoom(Room rooms[], int size) {
    int roomNo;
    string name;

    cout << "Enter Room Number: ";
    cin >> roomNo;

    for (int i = 0; i < size; i++) {
        if (rooms[i].roomNo == roomNo) {
            if (rooms[i].isBooked) {
                cout << "Already booked!\n";
                return;
            }
            cout << "Enter Name: ";
            cin >> name;

            rooms[i].isBooked = true;
            rooms[i].customerName = name;
            cout << "Booking successful!\n";
            return;
        }
    }
    cout << "Room not found!\n";
}

// Checkout
void checkout(Room rooms[], int size) {
    int roomNo;
    cout << "Enter Room Number: ";
    cin >> roomNo;

    for (int i = 0; i < size; i++) {
        if (rooms[i].roomNo == roomNo) {
            if (!rooms[i].isBooked) {
                cout << "Room already empty!\n";
                return;
            }
            rooms[i].isBooked = false;
            rooms[i].customerName = "";
            cout << "Checkout successful!\n";
            return;
        }
    }
}

// Search
void searchRoom(Room rooms[], int size) {
    string type;
    cout << "Enter Room Type (Single/Double/Deluxe): ";
    cin >> type;

    cout << "\nAvailable Rooms:\n";
    for (int i = 0; i < size; i++) {
        if (rooms[i].type == type && !rooms[i].isBooked) {
            cout << "Room " << rooms[i].roomNo
                 << " Price: " << rooms[i].price << endl;
        }
    }
}

// Generate bill
void generateBill(Room rooms[], int size) {
    int roomNo, days;
    cout << "Enter Room Number: ";
    cin >> roomNo;
    cout << "Enter Days: ";
    cin >> days;

    for (int i = 0; i < size; i++) {
        if (rooms[i].roomNo == roomNo && rooms[i].isBooked) {
            float total = rooms[i].price * days;

            ofstream bill("bill.txt");
            bill << "----- HOTEL BILL -----\n";
            bill << "Room: " << roomNo << endl;
            bill << "Customer: " << rooms[i].customerName << endl;
            bill << "Days: " << days << endl;
            bill << "Price/Day: " << rooms[i].price << endl;
            bill << "Total: " << total << endl;

            cout << "Bill generated! Total = " << total << endl;
            return;
        }
    }
    cout << "Invalid room!\n";
}

// MAIN
int main() {
    if (!login()) return 0;

    Room rooms[5] = {
        {101, "Single", 1000, false, "-"},
        {102, "Double", 1500, false, "-"},
        {103, "Deluxe", 2000, false, "-"},
        {104, "Single", 1000, false, "-"},
        {105, "Double", 1500, false, "-"}
    };

    loadFromFile(rooms, 5);

    int choice;
    do {
        cout << "\n===== HOTEL MENU =====\n";
        cout << "1. View Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Checkout\n";
        cout << "4. Search Room\n";
        cout << "5. Generate Bill\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayRooms(rooms, 5); break;
            case 2: bookRoom(rooms, 5); break;
            case 3: checkout(rooms, 5); break;
            case 4: searchRoom(rooms, 5); break;
            case 5: generateBill(rooms, 5); break;
            case 6:
                saveToFile(rooms, 5);
                cout << "Data saved. Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}