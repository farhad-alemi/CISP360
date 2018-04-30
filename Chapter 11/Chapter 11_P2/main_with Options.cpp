#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void Input_Module(ShoppingCart& list);
void change_quantity(ShoppingCart& list);
void remove_quantity(ShoppingCart& list);

int main()
{
    cout << fixed << setprecision(2);

    char   menu_choice;
    string customer_name,
           temp_phrase;
     
    // Customer Info
    cout << "Name:" << endl;
    getline(cin, customer_name);
    ShoppingCart list(customer_name);
    cout << endl;
    do
    {
        cout << "(a) Add Item" << endl;
        cout << "(c) Change Quantity" << endl;
        cout << "(r) Remove Item" << endl;
        cout << "(q) Quit" << endl;
        cin >> menu_choice;
        cin.ignore();

        if (menu_choice == 'a')
        {
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

            // Output Items
            list.printCart();
        }
        else if (menu_choice == 'c')
        {
            change_quantity(list);
        }
        else if (menu_choice == 'r')
        {
            remove_quantity(list);
        }
    }
    while (menu_choice != 'q');
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

void change_quantity(ShoppingCart& list)
{
    string temp_phrase;
    int    temp_quantity;

    cout << "Enter the item name: " << endl;
    getline(cin, temp_phrase);
    cout << "Enter new quantity: " << endl;
    cin >> temp_quantity;

    list.changeQuantity(temp_phrase, temp_quantity);
}

void remove_quantity(ShoppingCart& list)
{
    string temp_phrase;

    cout << "Enter the item name: " << endl;
    getline(cin, temp_phrase);

    list.removeItem(temp_phrase);
}