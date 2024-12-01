#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

class Bill {
    string Item;
    int rate, quantity;

public:
    Bill() : Item(""), rate(0), quantity(0) {}
    Bill(string item, int rate, int quantity) {
        this->Item = item;
        this->rate = rate;
        this->quantity = quantity;
    }
    string getItem() { return Item; }
    int getRate() { return rate; }
    int getQuantity() { return quantity; }
    void display() {
        cout << "\tItem: " << Item << endl;
        cout << "\tRate: " << rate << endl;
        cout << "\tQuantity: " << quantity << endl;
    }
};

void addItem() {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\n1. Add item" << endl;
        cout << "2. Close" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int rate, quantity;
            cout << "\tEnter item name: ";
            cin >> item;
            cout << "\tEnter rate: ";
            cin >> rate;
            cout << "\tEnter quantity: ";
            cin >> quantity;

            Bill b(item, rate, quantity);

            ofstream out("bill.txt", ios::app);
            if (!out) {
                cout << "\tError in opening file" << endl;
            } else {
                out << b.getItem() << " " << b.getRate() << " " << b.getQuantity() << endl;
                out.close();
                cout << "\tItem added successfully!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
        } else if (choice == 2) {
            system("clear");
            close = true;
            cout << "\tBack to main menu!" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        } else {
            cout << "\tInvalid choice. Try again." << endl;
        }
    }
}

void printBill() {
    ifstream in("bill.txt");
    if (!in) {
        cout << "\tNo bill available. Please add items first." << endl;
        return;
    }

    string item;
    int rate, quantity;
    long long total = 0;

    cout << "\n\t--- Bill Summary ---" << endl;
    cout << "\tItem\tRate\tQuantity\tAmount" << endl;

    while (in >> item >> rate >> quantity) {
        int amount = rate * quantity;
        total += amount;
        cout << "\t" << item << "\t" << rate << "\t" << quantity << "\t\t" << amount << endl;
    }
    in.close();

    cout << "\t-----------------------------" << endl;
    cout << "\tTotal Bill: " << total << endl;

    // Clear the bill file after printing
    ofstream out("bill.txt", ios::trunc);
    if (!out) {
        cout << "\tError clearing the bill." << endl;
    } else {
        cout << "\tBill cleared successfully!" << endl;
    }
    out.close();

    this_thread::sleep_for(chrono::milliseconds(3000));
}

int main() {
    bool exit = false;
    while (!exit) {
        system("clear");
        int value;
        cout << "\n\tWelcome to Super Market Billing System" << endl;
        cout << "\t-----------------------------------------" << endl;
        cout << "\t1. Add item to bill" << endl;
        cout << "\t2. Print bill" << endl;
        cout << "\t3. Exit" << endl;
        cout << "\t-----------------------------------------" << endl;
        cout << "\tEnter your choice: ";
        cin >> value;

        switch (value) {
            case 1:
                addItem();
                break;
            case 2:
                printBill();
                break;
            case 3:
                exit = true;
                cout << "\tExiting the program. Goodbye!" << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
                break;
            default:
                cout << "\tInvalid choice. Try again." << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
        }
    }

    return 0;
}
