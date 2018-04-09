#include <iostream>
#include <string>

#define SIZE 1000

int searchInputs(std::string text_array[], std::string temp_text, int list_counter);
void sortInputs(std::string text_array[], int frequency_array[], int list_counter);
void output_arrays(std::string text_array[], int frequency_array[], int list_counter);

int main() 
{
    std::string user_input,
                text_array[SIZE],
                temp_text;
    int         user_option,
                list_counter,
                duplicate_location,
                frequency_array[SIZE];

    // initialization
    list_counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        frequency_array[i] = 0;
    }
  
    do
    {
        // main menu
        std::cout << "(1) Enter a string" << std::endl;
        std::cout << "(2) Print a sorted list of inputs and their frequencies"
            << std::endl;
        std::cout << "(3) Quit" << std::endl;
        std::cin >> user_option;
    
        // choice #1
        if (user_option == 1)
        {
            std::cin.ignore();
            std::cout << "Enter a string: ";
            getline(std::cin, temp_text);
            duplicate_location = searchInputs(text_array, temp_text, list_counter);

            if (duplicate_location == -1)
            {
                text_array[list_counter] = temp_text;
                frequency_array[list_counter] = 1;
                list_counter++;
            }
            else
            {
                frequency_array[duplicate_location]++;
            }
        }
        else if (user_option == 2)
        {
            sortInputs(text_array, frequency_array, list_counter);
            output_arrays(text_array, frequency_array, list_counter);
        }
    }
    while (user_option != 3);
}

//
int searchInputs(std::string text_array[], std::string temp_text, int list_counter)
{
    for (int i = 0; i < list_counter; i++)
    {
        if (text_array[i] == temp_text)
        {
            return i;
        }
    }
    return -1;
}

//
void sortInputs(std::string text_array[], int frequency_array[], int list_counter)
{
    int         i = 0;
    int         j = 0;
    int         frequency_temp = 0; // temporary variable for swapping freq array
    std::string string_temp;        // temporary variable for swapping string array
    
    for (i = 1; i < list_counter; ++i)
    {
        j = i;
        // insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && text_array[j] < text_array[j - 1])
        {
            string_temp = text_array[j];
            text_array[j] = text_array[j - 1];
            text_array[j - 1] = string_temp;

            // swap the same indexes in the frequency_array
            frequency_temp = frequency_array[j];
            frequency_array[j] = frequency_array[j - 1];
            frequency_array[j - 1] = frequency_temp;
            
            --j;
        }
    }
}

//
void output_arrays(std::string text_array[], int frequency_array[], int list_counter)
{
    for (int i = 0; i < list_counter; i++)
    {
        std::cout << "Input: " << text_array[i] << std::endl;
        std::cout << "Frequency: " << frequency_array[i] << std::endl;
    }
}