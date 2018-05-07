#include "ContactNode.h"

void Input_Module(string& temp_name, string& temp_phone, int count);

int main()
{
    ContactNode *headObj = nullptr,     // Create ContactNode objects
                *currObj = nullptr,
                *lastObj = nullptr;

    for (int i = 0; i < LIST_SIZE; i++)
    {
        string temp_name,
               temp_phone;
        
        Input_Module(temp_name, temp_phone, i + 1);

        currObj = new ContactNode(temp_name, temp_phone);

        if (i == 0)
        {
            headObj = currObj;
        }
        else
        {
            lastObj->insertAfter(currObj);
        }
        lastObj = currObj;
    }
    currObj = headObj;

    cout << "CONTACT LIST" << endl;
    while (currObj != nullptr)
    {
        currObj->printContactNode();
        currObj = currObj->getNext();
    }
}

void Input_Module(string& temp_name, string& temp_phone, int count)
{
    cout << "Person " << count << endl;
    cout << "Enter name:" << endl;
    getline(cin, temp_name);
    cout << "Enter phone number:" << endl;
    getline(cin, temp_phone);
}