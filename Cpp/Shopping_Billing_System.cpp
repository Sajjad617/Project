#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

vector<Item> storeItems;
map<string, string> users;
string loggedInUser;

// Forward declarations
void loadUsers();
void saveUser(const string& username, const string& password);
void loadItems();
void saveItems();
string getPassword();
bool registerUser();
bool loginUser();
void addItem();
void editItem();
void deleteItem();
void showStoreItems();
void buyItems();

string getPassword() {
    string password;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == 13) break;
        else if (ch == 8 && !password.empty()) {
            password.pop_back();
            cout << "\b \b";
        } else if (ch != 8) {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

void loadUsers() {
    ifstream file("users.txt");
    string username, password;
    while (file >> username >> password) {
        users[username] = password;
    }
    file.close();
}

void saveUser(const string& username, const string& password) {
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
}

bool registerUser() {
    string username, password;
    cout << "Register\nUsername: ";
    cin >> username;
    if (users.find(username) != users.end()) {
        cout << "User already exists!\n";
        return false;
    }
    cout << "Password: ";
    password = getPassword();

    

    users[username] = password;
    saveUser(username, password);
    cout << "Registration successful.\n";
    return true;
}

bool loginUser() {
    string username, password;
    cout << "Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    password = getPassword();

    if (users.find(username) != users.end() && users[username] == password) {
        loggedInUser = username;
        cout << "Login successful.\n";
        return true;
    }

    cout << "Invalid credentials.\n";
    return false;
}

void loadItems() {
    ifstream file("items.txt");
    storeItems.clear();
    Item item;
    while (file >> item.name >> item.price >> item.quantity) {
        storeItems.push_back(item);
    }
    file.close();
}

void saveItems() {
    ofstream file("items.txt");
    for (auto& item : storeItems) {
        file << item.name << " " << item.price << " " << item.quantity << endl;
    }
    file.close();
}

void addItem() {
    Item item;
    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter price: ";
    cin >> item.price;
    cout << "Enter quantity: ";
    cin >> item.quantity;
    storeItems.push_back(item);
    saveItems();
    cout << "Item added.\n";
}

void editItem() {
    string name;
    cout << "Enter item name to edit: ";
    cin >> name;
    for (auto& item : storeItems) {
        if (item.name == name) {
            cout << "New price: ";
            cin >> item.price;
            cout << "New quantity: ";
            cin >> item.quantity;
            saveItems();
            cout << "Item updated.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void deleteItem() {
    string name;
    cout << "Enter item name to delete: ";
    cin >> name;
    for (auto it = storeItems.begin(); it != storeItems.end(); ++it) {
        if (it->name == name) {
            storeItems.erase(it);
            saveItems();
            cout << "Item deleted.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void showStoreItems() {
    cout << "\n--- Available Products ---\n";
    cout << left << setw(15) << "Item" << setw(10) << "Price" << setw(10) << "Stock" << "\n";
    for (auto& item : storeItems) {
        cout << left << setw(15) << item.name << setw(10) << item.price << setw(10) << item.quantity << "\n";
    }
}

void buyItems() {
    vector<Item> cart;
    string name;
    int qty;

    while (true) {
        showStoreItems();
        cout << "\nEnter item to buy (or 'end' to finish): ";
        cin >> name;
        if (name == "end") break;

        bool found = false;
        for (auto& item : storeItems) {
            if (item.name == name) {
                cout << "Quantity: ";
                cin >> qty;
                if (qty > item.quantity) {
                    cout << "Only " << item.quantity << " available.\n";
                } else {
                    Item purchased = item;
                    purchased.quantity = qty;
                    cart.push_back(purchased);
                    item.quantity -= qty;
                }
                found = true;
                break;
            }
        }
        if (!found) cout << "Item not found.\n";
    }

    if (!cart.empty()) {
        double total = 0;
        cout << "\n========== Shop Receipt ==========\n";
        cout << "Customer: " << loggedInUser << "\n";
        cout << left << setw(15) << "Item" 
             << setw(10) << "Qty" 
             << setw(10) << "Price" 
             << setw(10) << "Total" << "\n";
        cout << "-------------------------------------------\n";

        for (auto& item : cart) {
            double itemTotal = item.quantity * item.price;
            total += itemTotal;
            cout << left << setw(15) << item.name 
                 << setw(10) << item.quantity 
                 << setw(10) << item.price 
                 << setw(10) << itemTotal << "\n";
        }

        cout << "-------------------------------------------\n";

        double discount = (total > 1000.0) ? total * 0.05 : 0;
        double afterDiscount = total - discount;
        double tax = afterDiscount * 0.05;
        double finalTotal = afterDiscount + tax;

        cout << fixed << setprecision(2);
        cout << "Subtotal       : " << total << " Taka\n";
        cout << "Discount (5%)  : " << discount << " Taka\n";
        cout << "Tax (5%)       : " << tax << " Taka\n";
        cout << "-------------------------------------------\n";
        cout << "Total Payable  : " << finalTotal << " Taka\n";
        cout << "===========================================\n";
        cout << "Thank you for shopping with us!\n";

        saveItems(); // update stock
    } 
    else 
    {
        cout << "No items purchased.\n";
    }

    // if (!cart.empty()) {
    //     double total = 0;
    //     cout << "\n----- BILL -----\n";
    //     cout << "Customer: " << loggedInUser << "\n";
    //     cout << left << setw(15) << "Item" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Total" << "\n";
    //     for (auto& item : cart) {
    //         double itemTotal = item.quantity * item.price;
    //         total += itemTotal;
    //         cout << left << setw(15) << item.name << setw(10) << item.quantity << setw(10) << item.price << setw(10) << itemTotal << "\n";
    //     }

    //     double discount = (total > 1000.0) ? total * 0.05 : 0;
    //     double afterDiscount = total - discount;
    //     double tax = afterDiscount * 0.05;
    //     double finalTotal = afterDiscount + tax;

    //     cout << "\nSubtotal: " << total;
    //     cout << "\nDiscount: " << discount;
    //     cout << "\nTax: " << tax;
    //     cout << "\nTotal Payable: " << finalTotal << "\n";
    //     cout << "----------------------\n";
    //     saveItems(); // update stock
    // } else {
    //     cout << "No items purchased.\n";
    // }
}

int main() {
    users["admin"] = "admin"; // default admin
    loadUsers();
    loadItems();

    int choice;
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) 
        {
            registerUser();
        } 
        else if (choice == 2) 
        {
            if (loginUser()) {
                while (true) {
                    if (loggedInUser == "admin") {
                        cout << "\nAdmin Menu:\n1. Add Item\n2. Edit Item\n3. Delete Item\n4. View Items\n5. Logout\nChoose: ";
                        cin >> choice;
                        if (choice == 1) addItem();
                        else if (choice == 2) editItem();
                        else if (choice == 3) deleteItem();
                        else if (choice == 4) showStoreItems();
                        else break;
                    } 
                    else {
                        cout << "\nCustomer Menu:\n1. View & Buy Items\n2. Logout\nChoose: ";
                        cin >> choice;
                        if (choice == 1) buyItems();
                        else break;
                    }
                }
            }
        } 
        else
        {
            cout << "Thank You For Visiting Our Shopping Mall." << endl;
            break;
        }
    }

    return 0;
}