#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void Input_Module(ShoppingCart& list);

int main()
{
    string       customer_name;

    cout << fixed << setprecision(2);

    // Customer Info
    cout << "Name:" << endl;
    getline(cin, customer_name);
    ShoppingCart list(customer_name);

   // 1st Object
   Input_Module(list);

   cin.ignore();
   cout << endl;

   // 2nd Object
   Input_Module(list);

   cin.ignore();
   cout << endl;

   // 3rd Object
   Input_Module(list);

   // Output
   list.printCart();
}

void Input_Module(ShoppingCart& list)
{
    string temp_name;
    int    temp_quantity;
    double temp_price;

    cout << "Enter the item name:" << endl;
    getline(cin, temp_name);

    cout << "Enter the item price:" << endl;
    cin >> temp_price;

    cout << "Enter the item quantity:" << endl;
    cin >> temp_quantity;
    
    list.addItem({temp_name, temp_price, temp_quantity});
}