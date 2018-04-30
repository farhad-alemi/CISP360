#pragma once
#include "ItemToPurchase.h"
class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string name);
    string getCustomerName() const;
    void addItem(ItemToPurchase object);
    void removeItem(string phrase);
    void changeQuantity(string phrase, int quantity);
    double getTotalCost();
    void printCart();

private:
    string customerName;
    vector<ItemToPurchase> cartItems;
};