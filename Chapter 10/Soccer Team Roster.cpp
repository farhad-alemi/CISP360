#include <iostream>
#include <vector>
#include <algorithm>

struct player
{
    int number,
        rating;
};

char display_menu();
void add_player(std::vector<player>& all_players);
void output_roster(const std::vector<player>& all_players);
void delete_player(std::vector<player>& all_players);
void update_player(std::vector<player>& all_players);
void output_above_rating(const std::vector<player>& all_players);
bool compare_by_rating(const player& a, const player &b);
bool compare_by_number(const player& a, const player &b);

int main()
{
    char menu_choice;
    std::vector<player> all_players;

    do
    {
        menu_choice = display_menu();

        // Add player
        if (menu_choice == 'a')
        {
            add_player(all_players);
        }

        // Output menu
        else if (menu_choice == 'o')
        {
            output_roster(all_players);
        }

        // Delete player
        else if (menu_choice == 'd')
        {
            delete_player(all_players);
        }

        // Update player rating
        else if (menu_choice == 'u')
        {
            update_player(all_players);
        }

        // Output players above a rating
        else if (menu_choice == 'r')
            output_above_rating(all_players);

        // Sort by player rating
        else if (menu_choice == 's')
        {
            std::sort(all_players.begin(), all_players.end(), compare_by_rating);
        }
        
        // Sort by jersey number
        else if (menu_choice == 'j')
        {
            std::sort(all_players.begin(), all_players.end(), compare_by_number);
        }
    }
    while (menu_choice != 'q');
}

char display_menu()
{
    char menu_choice;

    std::cout << "MENU" << std::endl;
    std::cout << "a - Add player" << std::endl;
    std::cout << "d - Remove player" << std::endl;
    std::cout << "u - Update player rating" << std::endl;
    std::cout << "r - Output players above a rating" << std::endl;
    std::cout << "o - Output roster" << std::endl;
    std::cout << "s - Sort roster by player rating" << std::endl;
    std::cout << "j - Sort roster by jersey number" << std::endl;
    std::cout << "q - Quit" << std::endl << std::endl;
    std::cout << "Choose an option: ";
    std::cin >> menu_choice;
    
    std::cout << std::endl;
    return menu_choice;
}

void add_player(std::vector<player>& all_players)
{
    player temp;
    do
    {
        std::cout << "Enter player's jersey number:" << std::endl;
        std::cin >> temp.number;
    }
    while (temp.number < 0 || temp.number > 99);
    
    do
    {
        std::cout << "Enter player's rating:" << std::endl;
        std::cin >> temp.rating;
    }
    while (temp.rating < 1 || temp.rating > 9);

    all_players.push_back(temp);
}

void output_roster(const std::vector<player>& all_players)
{
    std::cout << "ROSTER" << std::endl;
    for (int i = 0; i < all_players.size(); i++)
    {
        std::cout << "Player " << (i + 1) << " -- Jersey number: " << all_players
            .at(i).number << ", Rating: " << all_players.at(i).rating << std::endl;
    }
}

void delete_player(std::vector<player>& all_players)
{
    int temp_number,
        del_index = -1;

    do
    {
        std::cout << "Enter a jersey number:" << std::endl;
        std::cin >> temp_number;
    }
    while (temp_number < 0 || temp_number > 99);

    for (int i = 0; i < all_players.size(); i++)
    {
        if (all_players.at(i).number == temp_number)
        {
            del_index = i;
            break;
        }
    }
    
    if (del_index != -1)
    {
        all_players.erase(all_players.begin() + del_index);
    }
}

void update_player(std::vector<player>& all_players)
{
    player temp;
    int    temp_index = -1;

    do
    {
        std::cout << "Enter player's jersey number:" << std::endl;
        std::cin >> temp.number;
    }
    while (temp.number < 0 || temp.number > 99);

    for (int i = 0; i < all_players.size(); i++)
    {
        if (all_players.at(i).number == temp.number)
        {
            temp_index = i;
            break;
        }
    }

    if (temp_index != -1)
    {
        do
        {
            std::cout << "Enter a new rating for player:" << std::endl;
            std::cin >> temp.rating;
        }
        while (temp.rating < 1 || temp.rating > 9);

        all_players.at(temp_index).rating = temp.rating;
    }
}

void output_above_rating(const std::vector<player>& all_players)
{
    int temp_rating;

    do
    {
        std::cout << "Enter a rating:" << std::endl;
        std::cin >> temp_rating;
    }
    while (temp_rating < 0 || temp_rating > 9);

    std::cout << "ABOVE " << temp_rating << std::endl;

    for (int i = 0; i < all_players.size(); i++)
    {
        if (all_players.at(i).rating > temp_rating)
        {
            std::cout << "Player " << (i + 1) << " -- Jersey number: " << all_players
                .at(i).number << ", Rating: " << all_players.at(i).rating << std::endl;
        }
    }
}

bool compare_by_number(const player& a, const player &b)
{
    return a.number < b.number;
}

bool compare_by_rating(const player& a, const player &b)
{
    return a.rating < b.rating;
}