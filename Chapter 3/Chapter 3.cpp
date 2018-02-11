#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define RADIUS 10

int main()
{
    double distance,
           x,
           y;
    int   user_choice;

    srand(2018);

    std::cout << "1) Enter coordinate of particle" << std::endl << 
        "2) Generate random particle" << std::endl;
    std::cin >> user_choice;

    if (user_choice == 1)
    {
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;
    }
    else
    {
        x = rand() % 21;
        y = rand() % 21;
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }

    distance = sqrt (pow(x,2) + pow(y,2));

    if (abs(RADIUS - distance) < 0.01)
    {
        std::cout << "On" << std::endl;
    }
    else if (distance < RADIUS)
    {
        std::cout << "In" << std::endl;
    }
    else
    {
        std::cout << "Out" << std::endl;
    }
}