#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    vector<ItemToPurchase> cartItems;
}

ShoppingCart::ShoppingCart(string name)
{
    customerName = name;
    vector<ItemToPurchase> cartItems;
}

string ShoppingCart::getCustomerName() const
{
    return customerName;
}

void ShoppingCart::addItem(ItemToPurchase object)
{
    cartItems.push_back(object);
}

void ShoppingCart::removeItem(string phrase)
{
    for (int i = 0; i < cartItems.size(); ++i)
    {
        if (cartItems.at(i).getName() == phrase)
        {
            cartItems.erase(cartItems.begin() + i);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::changeQuantity(string phrase, int quantity)
{
    for (int i = 0; i < cartItems.size(); ++i)
    {
        if (cartItems.at(i).getName() == phrase)
        {
            cartItems.at(i).setQuantity(quantity);
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
}

double ShoppingCart::getTotalCost()
{
    double sum  = 0;

    for (int i = 0; i < cartItems.size(); i++)
    {
        sum += cartItems[i].getQuantity() * cartItems[i].getPrice();
    }
    return sum;
}

void ShoppingCart::printCart()
{
    cout << ShoppingCart::getCustomerName() << "'s Shopping Cart" << endl << endl;
    
    for (int i = 0; i < cartItems.size(); ++i)
    {
       cout << cartItems[i].getName() << " " << cartItems[i].getQuantity() << " @ $" << cartItems[i].getPrice() << " = $" << (cartItems[i].getQuantity() * cartItems[i].getPrice()) << endl;
    }
    cout << endl << "Total: $" << ShoppingCart::getTotalCost() << endl;
}