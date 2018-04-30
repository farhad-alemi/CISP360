#include "ItemToPurchase.h"

void Input_Module(ItemToPurchase& object);

int main()
{
    ItemToPurchase object1,
                   object2;
    double         total;

    cout << fixed << setprecision(2);
   // 1st Object
   Input_Module(object1);

   cin.ignore();
   cout << endl;

   // 2nd Object
   Input_Module(object2);

   // Output
   object1.printItemCost();
   object2.printItemCost();

   total = (object1.getPrice() * object1.getQuantity()) + (object2.getPrice()
       * object2.getQuantity());
   cout << endl << "Total: $" << total << endl;
}

void Input_Module(ItemToPurchase& object)
{
    string    temp_name;
    double         temp_price;
    int            temp_quantity;

    cout << "Enter the item name:" << endl;
    getline(cin, temp_name);
    //cin.ignore();

    cout << "Enter the item price:" << endl;
    cin >> temp_price;

    cout << "Enter the item quantity:" << endl;
    cin >> temp_quantity;

    object.setName(temp_name);
    object.setPrice(temp_price);
    object.setQuantity(temp_quantity);
}