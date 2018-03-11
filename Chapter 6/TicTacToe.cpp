// Program      :   TicTacToe - Chapter 6 Assignment
// Author       :   Farhad Alemi
// Due Date     :   March 9th, 2018
// Description  :   This program allows two players to play a game of tic-tac-toe

#include <iostream>

#define NUM_ROWS 3
#define NUM_COLS 3
#define RESET_CHAR '*'
#define PLAYER1_CHAR 'X'
#define PLAYER2_CHAR 'O'

void display_output(char game_array[][NUM_COLS]);
void validated_input(int player_num, char game_array[][NUM_COLS], char character);

int main()
{
    char game_board[NUM_ROWS][NUM_COLS];

    // Array Initialization
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            game_board[i][j] = RESET_CHAR;
        }
    }

    // Display Initialized Array
    display_output(game_board);

    do
    {
        validated_input(1, game_board, PLAYER1_CHAR);
        display_output(game_board);
        validated_input(2, game_board, PLAYER2_CHAR);
        display_output(game_board);
    }
    while (true);   // This infinite loop is ended by exit(EXIT_FAILURE)
}
    

//
// Displays the contents of the array and determine the result
//
void display_output(char game_array[][NUM_COLS])
{
    std::cout << " ";
    for (int i = 0; i < NUM_ROWS; i++)
        {
            std::cout << " " << (i + 1);
        }
    std::cout << std::endl;
    for (int i = 0; i < NUM_ROWS; i++)
    {
        std::cout << (i + 1);
        for (int j = 0; j < NUM_COLS; j++)
        {
            std::cout << " " << game_array[i][j];
        }
        std::cout << std::endl;
    }
}


//
// Performs calculations
//
void validated_input(int player_num, char game_array[][NUM_COLS], char character)
{
    bool reserved = false;
    int  counter,           // Counts Xs or Os
         row,
         column;

    do
    {
        do
        {
            std::cout << "Player " << player_num << ", Row: ";
            std::cin >> row;
        }
        while (row <= 0 || row > NUM_ROWS);
        row--;

        do
        {
            std::cout << "Player " << player_num << ", Column: ";
            std::cin >> column;
        }
        while (column <= 0 || column > NUM_COLS);
        column--;

        if ((game_array[row][column]) != RESET_CHAR)
        {
            reserved = true;
        }
        else
        {
            reserved = false;
        }
    }
    while (reserved);
    game_array[row][column] = character;

    for (int i = 0; i < NUM_ROWS; i++)
    {
        counter = 0;
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (game_array[i][j] == character)
            {
                counter++;
            }
        }
        if (counter == NUM_COLS)
        {
            display_output(game_array);
            std::cout << "Player " << player_num << " wins!" << std::endl;
            exit (EXIT_FAILURE);
        }
    }
    
    for (int i = 0; i < NUM_ROWS; i++)
    {
        counter = 0;
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (game_array[j][i] == character)
            {
                counter++;
            }
        }
        if (counter == NUM_ROWS)
        {
            display_output(game_array);
            std::cout << "Player " << player_num << " wins!" << std::endl;
            exit (EXIT_FAILURE);
        }
    }

    counter = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {
        if (game_array[i][i] == character)
        {
            counter++;
        }
        if (counter == NUM_ROWS)
        {
            display_output(game_array);
            std::cout << "Player " << player_num << " wins!" << std::endl;
            exit (EXIT_FAILURE);
        }
    }

    counter = 0;
    for (int i = (NUM_ROWS - 1); i >= 0; --i)
    {
        if (game_array[i][NUM_ROWS - 1 - i] == character)
        {
            counter++;
        }
        if (counter == NUM_ROWS)
        {
            display_output(game_array);
            std::cout << "Player " << player_num << " wins!" << std::endl;
            exit (EXIT_FAILURE);
        }
    }

    counter = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (game_array[i][j] == RESET_CHAR)
            {
                counter++;
            }
        }
    }
    if (counter == 0)
    {
        display_output(game_array);
        std::cout << "Tie!" << std::endl;
        exit (EXIT_FAILURE);
    }
}