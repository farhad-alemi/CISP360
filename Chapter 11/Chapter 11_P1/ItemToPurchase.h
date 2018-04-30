#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ItemToPurchase
{
    private:
        string itemName;
        double itemPrice;
        int itemQuantity;

    public:
        ItemToPurchase();
        ItemToPurchase(string name, double price, int quantity);
        void setName(string name);
        void setPrice(double price);
        void setQuantity(int quantity);
        string getName() const;
        double getPrice() const;
        int getQuantity() const;
        void printItemCost();
};