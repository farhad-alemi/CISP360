#include <iostream>
#include <string>
using namespace std;

void PrintMenu(string user_input, char& user_option);
int getNumOfNonWSCharacters(const string usrStr);
int getNumOfWords(const string usrStr);
int findText(const string toFind, string usrStr);
void replaceExclamation(string& usrStr);
void shortenSpace(string& usrStr);

int main()
{
    string user_input;
    char user_option;

    // input section
    cout << "Enter a sample text: " << endl;
    getline(cin, user_input);

    // user output
    cout << endl;
    cout << "You entered: " << user_input << endl;

    do
    {
        PrintMenu(user_input, user_option);
    }
    while (user_option != 'q');
}


// display program menu
void PrintMenu(string user_input, char& user_option)
{
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl << endl;

    cout << "Choose an option:" << endl;
    cin >> user_option;

    // c
    if (user_option == 'c')
    {
        int counter = getNumOfNonWSCharacters(user_input);
        cout << "Number of non-whitespace characters: " << counter
            << endl;
    }

    // w
    else if (user_option == 'w')
    {
        int counter = getNumOfWords(user_input);
        cout << "Number of words: " << counter << endl;
    }

    // f
    else if (user_option == 'f')
    {
        int counter;
        string search_phrase;

        cout << "Enter a word or phrase to be found:" << endl;
        cin.ignore();
        getline(cin, search_phrase);
        counter = findText(search_phrase, user_input);
        cout << "\"" << search_phrase << "\" instances: " << counter
            << endl;

    }
    // r
    else if (user_option == 'r')
    {
        replaceExclamation(user_input);
        cout << "Edited text: " << user_input << endl;
    }

    // s
    else if (user_option == 's')
    {
        shortenSpace(user_input);
        cout << "Edited text: " << user_input << endl << endl;
    }
}


// number of non-whtie space characters
int getNumOfNonWSCharacters(const string usrStr)
{
    int counter = 0;

    for (int i = 0; i < usrStr.size(); i++)
    {
        if (!isspace(usrStr.at(i)))
        {
            counter++;
        }
    }
    return counter;
}


// number of words
int getNumOfWords(const string usrStr)
{
    int counter = 0;
    for (int i = 0; i < usrStr.size(); i++)
    {
        if (isspace(usrStr.at(i)) && (!isspace(usrStr.at(i - 1))))
        {
            counter++;
        }
    }
    return counter + 1; 
}


// find text
int findText(const string toFind, string usrStr)
{
    size_t last_found = usrStr.find(toFind);
    int counter = 0;

    for (size_t i = last_found; i < usrStr.size(); i++)
    {
        if (usrStr.find(toFind, last_found) != string::npos)
        {
            counter++;
            last_found = usrStr.find(toFind, last_found + 1);
        }
        else
        {
            break;
        }
    }
    return counter;
}


// replace exclamation
void replaceExclamation(string& usrStr)
{
    for (int i = 0; i < usrStr.size(); i++)
    {
        if (usrStr.at(i) == '!')
        {
            usrStr.at(i) = '.';
        }
    }
}


// shorten space
void shortenSpace(string& usrStr)
{
    for (int i = 0; i < usrStr.size() - 1; i++) 
    {
        if(isspace(usrStr.at(i)) && isspace(usrStr.at(i+1)))
        {
            usrStr.erase(i,1);
            i--;
        }
    }
}