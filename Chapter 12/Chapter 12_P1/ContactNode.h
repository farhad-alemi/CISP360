#pragma once
#include <iostream>
#include <string>
using namespace std;

#define LIST_SIZE 3

class ContactNode
{
public:
    ContactNode();
    ContactNode(string initName, string initPhoneNum, ContactNode* nextLoc = 0);
    void insertAfter(ContactNode* nodePtr);
    string getName() const;
    string getPhoneNumber() const;
    ContactNode* getNext();
    void printContactNode();

private:
    string  contactName;
    string  contactPhoneNum;
    ContactNode* nextNodePtr;
};