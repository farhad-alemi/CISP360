#include <iostream>
#include <string>

int main ()
{
    std::string full_name,
                city;
    int         age;

    std::cout << "What is your name? ";
    getline(std::cin, full_name);
    std::cout << "What is you age? ";
    std::cin >> age;
    std::cout << "What is your favorite city? ";
    std::cin.ignore();
    getline(std::cin, city);

    std::cout << "Hello " << full_name << "!  " << age << " is a great age. I like "
        << city << " too!" << std::endl;
}