#include "ContactNode.h"

ContactNode::ContactNode()
{
    contactName = "";
    contactPhoneNum = "";
    nextNodePtr = nullptr;
}

ContactNode::ContactNode(string initName, string initPhoneNum, ContactNode* nextLoc)
{
    contactName = initName;
    contactPhoneNum = initPhoneNum;
    nextNodePtr = nextLoc;
}

void ContactNode::insertAfter(ContactNode* nodePtr)
{
    ContactNode* tempNext;

    tempNext = nextNodePtr;
    nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = tempNext;
}

string ContactNode::getName() const
{
    return contactName;
}

string ContactNode::getPhoneNumber() const
{
    return contactPhoneNum;
}

ContactNode* ContactNode::getNext()
{
    return nextNodePtr;
}

void ContactNode::printContactNode()
{
    cout << "Name: " << ContactNode::getName() << endl;
    cout << "Phone number: " << ContactNode::getPhoneNumber() << endl;
}