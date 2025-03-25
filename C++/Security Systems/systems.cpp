#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits> // Required for numeric_limits

using namespace std;

// Function to clear the input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int choice;
    string username, password, newPassword1, newPassword2, storedUsername, storedPassword, storedAge;
    string credentials[2];

    cout << "         Security System " << endl;
    cout << " ______________________________" << endl << endl;
    cout << "|         1. Register          |" << endl;
    cout << "|         2. Login             |" << endl;
    cout << "|         3. Change password   |" << endl;
    cout << "|_________4. End Program_______|" << endl << endl;

    do {
        cout << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer after reading an integer to prevent issues with getline
        clearInputBuffer();

        switch (choice) {
        case 1: {
            cout << "___________________________" << endl << endl;
            cout << "|--------Register---------|" << endl;
            cout << "|_________________________|" << endl << endl;
            cout << "Please enter username: ";
            getline(cin, username);
            cout << "Enter your password: ";
            getline(cin, password);
            cout << "Please enter your age: ";
            getline(cin, storedAge); // Store age as string for simplicity

            ofstream outputFile("file.txt", ios::app); // Append to the file
            if (outputFile.is_open()) {
                outputFile << username << "\n";
                outputFile << password << "\n";
                cout << "Registration Successful." << endl;
                outputFile.close();
            } else {
                cout << "Error opening file for registration." << endl;
            }
            break;
        }

        case 2: {
            cout << "___________________________" << endl << endl;
            cout << "|---------Login-----------|" << endl;
            cout << "|_________________________|" << endl << endl;

            cout << "Please enter your username: ";
            getline(cin, username);
            cout << "Please enter your password: ";
            getline(cin, password);

            ifstream inputFile("file.txt");
            bool loggedIn = false;
            if (inputFile.is_open()) {
                while (getline(inputFile, storedUsername)) {
                    if (getline(inputFile, storedPassword)) {
                        if (username == storedUsername && password == storedPassword) {
                            cout << "---Login successful---" << endl << endl;
                            cout << "Details: " << endl;
                            cout << "Username: " << username << endl;
                            cout << "Password: " << password << endl;
                            // Note: Age is not being read back during login in this version.
                            // You would need to modify the file reading logic if you want to retrieve it.
                            cout << "Age: " << storedAge << endl;
                            loggedIn = true;
                            break;
                        }
                    }
                }
                inputFile.close();
            } else {
                cout << "Error opening file for login." << endl;
            }

            if (!loggedIn) {
                cout << endl << endl;
                cout << "Incorrect Credentials" << endl;
                cout << "|   1. Press 2 to login              |" << endl;
                cout << "|   2. Press 3 to change password    |" << endl;
            }
            break;
        }

        case 3: {
            cout << "-------------Change password-------------" << endl;
            cout << "Enter your current username: ";
            getline(cin, username);
            cout << "Enter your old password: ";
            getline(cin, password);

            ifstream inputFile("file.txt");
            string tempUsername, tempPassword;
            bool foundUser = false;

            // Read the file to find the user
            while (getline(inputFile, tempUsername)) {
                if (getline(inputFile, tempPassword)) {
                    if (username == tempUsername && password == tempPassword) {
                        foundUser = true;
                        break;
                    }
                }
            }
            inputFile.close();

            if (foundUser) {
                cout << "Enter your new password: ";
                getline(cin, newPassword1);
                cout << "Re-enter your new password: ";
                getline(cin, newPassword2);

                if (newPassword1 == newPassword2) {
                    // Rewrite the file with the new password
                    ofstream outputFile("file.txt");
                    if (outputFile.is_open()) {
                        outputFile << username << "\n";
                        outputFile << newPassword1 << "\n";
                        cout << "Password changed successfully." << endl;
                        outputFile.close();
                    } else {
                        cout << "Error opening file for writing." << endl;
                    }
                } else {
                    cout << "New passwords do not match." << endl;
                }
            } else {
                cout << "Incorrect username or old password." << endl;
            }
            break;
        }

        case 4: {
            cout << "____________Thank you___________" << endl;
            break;
        }

        default:
            cout << "Enter a valid choice." << endl;
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0;
}