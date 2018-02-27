// Program      :       HVAC Controller.cpp
// Author       :       Farhad Alemi
// Due Date     :       February 25th, 2017
// Description  :       The code for a hyptothetical dual zone HVAC controller.
//                      Here are the requirements:
//                       Initialize the zone 1 temperature and zone 1 thermostat
//                        to 75 degrees
//                       Initialize the zone 2 temperature and zone 2 thermostat to
//                        80 degrees
//                       Initialize the controller status to HVAC OFF
//                       Initialize both dampers to CLOSED
//                       Run a loop that prints the status of the system and asks
//                       for user input with the numerical menu:

#include <iostream>

int main()
{
    bool damper1 = 0,
         damper2 = 0;
    int  temp_zone1 = 75,
         temp_zone2 = 80,
         thermo_zone1 = 75,
         thermo_zone2 = 80,
         user_choice,
         waiting_turns = 0;
    enum HVAC_STATUS {HVAC_OFF, AC_ON, FURNACE_ON};
    HVAC_STATUS mode = HVAC_OFF;

    do
    {
        if (waiting_turns == 0)
        {
            do
            {
                // HVAC Status
                std::cout << "Status:" << std::endl;
                switch (mode)
                {
                    case 0:
                        std::cout << "HVAC OFF" << std::endl;
                        break;
                    case 1:
                        std::cout << "AC ON" << std::endl;
                        break;
                    case 2:
                        std::cout << "FURNACE ON" << std::endl;
                        break;
                }

                // Damper Status
                std::cout << "Zone 1 damper is ";
                if (damper1 == 0)
                {
                    std::cout << "CLOSED" << std::endl;
                }
                else
                {
                    std::cout << "OPEN" << std::endl;
                }
                std::cout << "Zone 2 damper is ";
                if (damper2 == 0)
                {
                    std::cout << "CLOSED" << std::endl;
                }
                else
                {
                    std::cout << "OPEN" << std::endl;
                }

                // Temperatures
                std::cout << "Zone 1 temperature: " << temp_zone1 << std::endl;
                std::cout << "Zone 2 temperature: " << temp_zone2 << std::endl;

                // Menu Choices
                std::cout << "Enter a menu choice:" << std::endl;
                std::cout << "0) Quit" << std::endl << "1) Set thermostats" << std::endl
                    << "2) Wait 1 turn" << std::endl << "3) Wait 10 turns" << std::endl; 
                std::cin >> user_choice;
            }
            while ((user_choice != 0) && (user_choice != 1) && (user_choice != 2) && 
                (user_choice != 3));
        }

        // Immediate Exit
        if (user_choice == 0)
        {
            break;
        }

        // Set Thermostats
        else if (user_choice == 1)
        {
            std::cout << "Set the thermostat for zone 1: ";
            std::cin >> thermo_zone1;
            std::cout << "Set the thermostat for zone 2: ";
            std::cin >> thermo_zone2;
        }

        else if (waiting_turns == 0 && user_choice == 3)
         {
            waiting_turns = 10;
         }

        // HVAC Status Configuration
        if (temp_zone1 > thermo_zone1 || temp_zone2 > thermo_zone2)
        {
            mode = AC_ON;
            if (temp_zone1 > thermo_zone1)
            {
                damper1 = 1;
                if (user_choice == 2 || user_choice == 3)
                {
                    temp_zone1--;
                }
            }
            if (temp_zone2 > thermo_zone2)
            {
                damper2 = 1;
                if (user_choice == 2 || user_choice == 3)
                {
                    temp_zone2--;
                }
            }
        }
        else if (temp_zone1 < thermo_zone1 || temp_zone2 < thermo_zone2)
        {
            mode = FURNACE_ON;
            if (temp_zone1 < thermo_zone1)
            {
                damper1 = 1;
                if (user_choice == 2 || user_choice == 3)
                {
                    temp_zone1++;
                }
            }
            if (temp_zone2 < thermo_zone2)
            {
                damper2 = 1;
                if (user_choice == 2 || user_choice == 3)
                {
                    temp_zone2++;
                }
            }
        }
        if (temp_zone1 == thermo_zone1 && temp_zone2 == thermo_zone2)
        {
            mode = HVAC_OFF;
        }

        // Initialize Dampers to Be Closed
        if (temp_zone1 == thermo_zone1)
        {
            damper1 = 0;
        }
        if (temp_zone2 == thermo_zone2)
        {
            damper2 = 0;
        }

        // Waiting 10 turns
        if (user_choice == 3)
        {
            waiting_turns--;
        }
    }
    while (user_choice != 0);
}