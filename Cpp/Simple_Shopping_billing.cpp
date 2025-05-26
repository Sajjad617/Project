#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int MAX_ITEMS = 100;
    string itemName[MAX_ITEMS], customerName;
    int quantity[MAX_ITEMS], n;
    float price[MAX_ITEMS], total[MAX_ITEMS];
    float grandTotal = 0, discount = 0, tax = 0, finalTotal = 0;

    // Get customer name
    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    // Input items
    cout << "Enter number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nItem " << i + 1 << " name: ";
        cin >> itemName[i];
        cout << "Quantity: ";
        cin >> quantity[i];
        cout << "Price per unit: ";
        cin >> price[i];
        total[i] = quantity[i] * price[i];
        grandTotal += total[i];
    }

    // Discount logic
    if (grandTotal > 1000) {
        discount = grandTotal * 0.05;
    }

    // Tax calculation
    tax = (grandTotal - discount) * 0.05;
    finalTotal = grandTotal - discount + tax;

    // Print bill
    cout << "\n========== Shop Receipt ==========\n";
    cout << "Customer: " << customerName << endl;
    cout << left << setw(15) << "Item" << setw(10) << "Qty" 
         << setw(10) << "Price" << "Total\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << itemName[i] << setw(10) 
             << quantity[i] << setw(10) << price[i] << total[i] << endl;
    }

    cout << "-------------------------------------------\n";
    cout << "Subtotal       : " << grandTotal << " Taka\n";
    cout << "Discount (5%)  : " << discount << " Taka\n";
    cout << "Tax (5%)       : " << tax << " Taka\n";
    cout << "-------------------------------------------\n";
    cout << "Total Payable  : " << finalTotal << " Taka\n";
    cout << "===========================================\n";
    cout << "Thank you for shopping with us!\n";

    return 0;
}

// Output:
/*

Enter Customer Name: Rafi
Enter number of items: 2

Item 1 name: Soap
Quantity: 5
Price per unit: 30

Item 2 name: Rice
Quantity: 10
Price per unit: 60

========== Shop Receipt ==========
Customer: Rafi
Item           Qty       Price     Total
-------------------------------------------
Soap           5         30        150
Rice           10        60        600
-------------------------------------------
Subtotal       : 750 Taka
Discount (5%)  : 0 Taka
Tax (5%)       : 37.5 Taka
-------------------------------------------
Total Payable  : 787.5 Taka
===========================================
Thank you for shopping with us!


*/