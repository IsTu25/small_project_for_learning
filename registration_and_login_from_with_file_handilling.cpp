#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

class Login {
private:
    string LoginId, Password;
public:
    Login() : LoginId(""), Password("") {}
    void setId(string id) {
        LoginId = id;
    }
    void setPassword(string pass) {
        Password = pass;
    }
    string getId() {
        return LoginId;
    }
    string getPassword() {
        return Password;
    }
};

void registration(Login& log) {
    system("clear");  // Use "clear" instead of "cls" for non-Windows platforms
    string id, pw;
    cout << "Enter your id: " << endl;
    cin >> id;
    log.setId(id);

start:
    cout << "Enter your password: " << endl;
    cin >> pw;
    if (pw.length() >= 8) {
        log.setPassword(pw);
    } else {
        cout << "Password should be at least 8 characters long" << endl;
        goto start;
    }

    ofstream outfile("login.txt", ios::app);
    if (!outfile) {
        cout << "Error in opening file" << endl;
    } else {
        outfile << log.getId() << endl;
        outfile << log.getPassword() << endl;
        outfile.close();
        cout << "Registration successful" << endl;
    }
}

bool login() {
    system("clear");
    string id, pw, storedId, storedPw;
    cout << "Enter your id: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> pw;

    ifstream infile("login.txt");
    if (!infile) {
        cout << "Error in opening file" << endl;
        return false;
    }

    while (getline(infile, storedId) && getline(infile, storedPw)) {
        if (id == storedId && pw == storedPw) {
            cout << "Login successful!" << endl;
            return true;
        }
    }

    cout << "Invalid credentials!" << endl;
    return false;
}

int main() {
    Login log;
    bool exit = false;
    while (!exit) {
        system("clear");
        int choice;
        cout << "\t Welcome to Registration & Login Form" << endl;
        cout << "\t-----------------------------------------" << endl;
        cout << "\t 1. Registration" << endl;
        cout << "\t 2. Login" << endl;
        cout << "\t 3. Exit" << endl;
        cout << "\t-----------------------------------------" << endl;
        cout << "\t Enter your choice: ";
        cin >> choice;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        switch (choice) {
            case 1:
                registration(log);
                break;
            case 2:
                if (login()) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }
                break;
            case 3:
                exit = true;
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    return 0;
}
