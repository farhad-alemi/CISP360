#include <iostream>
#include <string>

void PrintMenu(std::string user_input, char& user_option);
int getNumOfNonWSCharacters(const std::string usrStr);
int getNumOfWords(const std::string usrStr);
int findText(const std::string toFind, std::string usrStr);
void replaceExclamation(std::string& usrStr);
void shortenSpace(std::string& usrStr);

int main()
{
    std::string user_input;
    char user_option;

    // input section
    std::cout << "Enter a sample text: " << std::endl;
    getline(std::cin, user_input);

    // user output
    std::cout << std::endl;
    std::cout << "You entered: " << user_input << std::endl;

    do
    {
        PrintMenu(user_input, user_option);
    }
    while (user_option != 'q');
}


// display program menu
void PrintMenu(std::string user_input, char& user_option)
{
    std::cout << "MENU" << std::endl;
    std::cout << "c - Number of non-whitespace characters" << std::endl;
    std::cout << "w - Number of words" << std::endl;
    std::cout << "f - Find text" << std::endl;
    std::cout << "r - Replace all !'s" << std::endl;
    std::cout << "s - Shorten spaces" << std::endl;
    std::cout << "q - Quit" << std::endl << std::endl;

    std::cout << "Choose an option:" << std::endl;
    std::cin >> user_option;

    // c
    if (user_option == 'c')
    {
        int counter = getNumOfNonWSCharacters(user_input);
        std::cout << "Number of non-whitespace characters: " << counter
            << std::endl;
    }

    // w
    else if (user_option == 'w')
    {
        int counter = getNumOfWords(user_input);
        std::cout << "Number of words: " << counter << std::endl;
    }

    // f
    else if (user_option == 'f')
    {
        int counter;
        std::string search_phrase;

        std::cout << "Enter a word or phrase to be found:" << std::endl;
        std::cin >> search_phrase;
        counter = findText(search_phrase, user_input);
        std::cout << "\"" << search_phrase << "\" instances: " << counter
            << std::endl;

    }
    // r
    else if (user_option == 'r')
    {
        replaceExclamation(user_input);
        std::cout << "Edited text: " << user_input << std::endl;
    }

    // s
    else if (user_option == 's')
    {
        shortenSpace(user_input);
        std::cout << "Edited text: " << user_input << std::endl;
    }
}


// number of non-whtie space characters
int getNumOfNonWSCharacters(const std::string usrStr)
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
int getNumOfWords(const std::string usrStr)
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
int findText(const std::string toFind, std::string usrStr)
{
    size_t last_found = usrStr.find(toFind);
    int counter = 0;

    for (size_t i = last_found; i < usrStr.size(); i++)
    {
        if (usrStr.find(toFind, last_found) != std::string::npos)
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
void replaceExclamation(std::string& usrStr)
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
void shortenSpace(std::string& usrStr)
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