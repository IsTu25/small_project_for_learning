#include <bits/stdc++.h>
using namespace std;

class ATM {
private:
    int balance;

public:
    ATM(int balance) {
        this->balance = balance;
    }

    int getBalance() {
        return balance;
    }

    bool withdraw(int amount) { 
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    void deposit(int amount) {
        balance += amount;
    }
};

int main() {
    ATM atm(1000);
    int choice;
    char op;

    do {
        cout << "\n--- ATM Menu ---" << endl;
        cout << "1. View Balance" << endl;
        cout << "2. Cash Withdraw" << endl;
        cout << "3. Cash Deposit" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Your Balance is: " << atm.getBalance() << endl;
            break;
        }
        case 2: {
            int amount;
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            if (atm.withdraw(amount)) {
                cout << "Withdrawal Successful" << endl;
            } else {
                cout << "Insufficient Balance" << endl;
            }
            break;
        }
        case 3: {
            int amount;
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            atm.deposit(amount);
            cout << "Deposit Successful" << endl;
            break;
        }
        case 4: {
            cout << "Thank you for using the ATM. Goodbye!" << endl;
            return 0;
        }
        default: {
            cout << "Invalid Choice. Please try again." << endl;
            break;
        }
        }

        cout << "\nDo you want to try another transaction [Yes/No]: ";
        cin >> op;
    } while (op == 'y' || op == 'Y');

    return 0;
}
