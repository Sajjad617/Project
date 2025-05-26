#include<bits/stdc++.h>
using namespace std;

// Create a map for store username and password
unordered_map<string, string> users;

//It's Function for Control Register
void registerUser() { 
    cout << "_____Create a new account_____" << endl;
    string username, password; // Variable

    cout << "Enter new username: " << endl;;
    cin >> username; // User Input

    // Check if the username is already taken
    if (users.find(username) != users.end()) 
    {
        cout << "Username already exists. You should change username." << endl;
        return;
    }
    cout << "Enter new password: " << endl;
    cin >> password; // User Input

    // Store username and password in map
    users[username] = password;

    cout << "Registration successful!" << endl;
}

//It's Function for Control Login
void loginUser() {
    cout << "_____Student Sign in_____" << endl;
    string username, password; // Variable

    // User Input
    cout << "Enter username: " << endl;
    cin >> username;
    cout << "Enter password: " << endl;
    cin >> password;

    // Check if username and password 
    if (users.find(username) != users.end() && users[username] == password) 
    {
        cout << "Login successful! Welcome, " << username << "!" << endl;
    } 
    else 
    {
        cout << "Invalid username or password." << endl;
    }
}

int main() // Main function that shows a menu and handles choices
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    while (true)  // Loop until user chooses to exit
    {    
        // Display menu
        cout << "_____ Students Management System Menu_____" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: " << endl;

        int choice;
        cin >> choice;
        // Handle user choice using switch-case        
        switch (choice) {
            case 1:
                registerUser();  // Call Function for Register
                break;
            case 2:
                loginUser();     // Call Function for Login
                break;
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;        // Exit the program
            default: 
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}