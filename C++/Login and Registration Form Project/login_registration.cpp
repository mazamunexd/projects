// login_registration.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // for setw

using namespace std;

// Function prototypes
void login();
void registration();
void forgot();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        cout << "\n\t\t\t Please enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forgot();
                break;
            case 4:
                cout << "\t\t\t Thank you! \n\n";
                break;
            default:
                cout << "\t\t\t Please select from the options given above \n" << endl;
        }
    } while (choice != 4); // Loop until the user chooses to exit
    return 0;
}

void displayMenu() {
    cout << "\t\t\t ____________________________________________\n\n\n";
    cout << "\t\t\t          Welcome to login page              \n\n\n";
    cout << "\t\t\t _____________     MENU      ________________\n\n\n";
    cout << "\t\t\t | Press 1 to LOGIN                        |\n";
    cout << "\t\t\t | Press 2 to REGISTER                     |\n";
    cout << "\t\t\t | Press 3 if you forgot your PASSWORD      |\n";
    cout << "\t\t\t | Press 4 to EXIT                         |\n";
}

void login() {
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");
    if (!input.is_open()) {
        cerr << "Error: Could not open records.txt for reading." << endl;
        return; // Exit the function if file cannot be opened
    }

    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            system("cls");
            break; // Exit the loop when a match is found
        }
    }
    input.close();

    if (count == 1) {
        cout << userId << "\n Your LOGIN is successful. \n Thanks for logging in! \n";
    } else {
        cout << "\n LOGIN ERROR \n Please check your username and password.\n";
    }
}

void registration() {
    string registerUserId, registerPassword;
    system("cls");
    cout << "\t\t\t Enter your username: ";
    cin >> registerUserId;
    cout << "\t\t\t Enter your password: ";
    cin >> registerPassword;

    ofstream f1("records.txt", ios::app);
    if (!f1.is_open()) {
        cerr << "Error: Could not open records.txt for appending." << endl;
        return; // Exit the function if file cannot be opened
    }

    f1 << registerUserId << ' ' << registerPassword << endl;
    f1.close(); //close the file.
    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\t Forgot Password? \n";
    cout << "Press 1 to search your ID by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice: " << endl;
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string searchUserId, searchId, searchPass;
            cout << "\n\t\t\t Enter the username you remember: ";
            cin >> searchUserId;

            ifstream f2("records.txt");
            if (!f2.is_open()) {
                cerr << "Error: Could not open records.txt for reading." << endl;
                return; // Exit the function if file cannot be opened
            }

            while (f2 >> searchId >> searchPass) {
                if (searchId == searchUserId) {
                    count = 1;
                    break; // Exit the loop when found.
                }
            }
            f2.close();

            if (count == 1) {
                cout << "\n\n Your account is found! \n";
                cout << " \n\n Your password is: " << searchPass;
            } else {
                cout << "\n\t Sorry we can't find your account. ";
            }
            break;
        }
        case 2:
            // Do nothing, just return to main menu.
            break;
        default:
            cout << "\t\t\t Wrong choice! Try again" << endl;
            forgot();
    }
}