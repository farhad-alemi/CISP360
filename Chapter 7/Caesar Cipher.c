#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 20 

void convertToUppercase(char pass_phrase[]);
void encrypt(char pass_phrase[], int shift_key);
void decrypt(char pass_phrase[], int shift_key);

int main(void)
{
    int  user_choice;
    int  shift_key;
    char pass_phrase[SIZE];

    do
    {
        do
        {
            printf("Enter the number of your selection:\n");
            printf("1. Encrypt\n");
            printf("2. Decrypt\n");
            printf("3. Exit\n");
            scanf("%d", &user_choice);
        }
        while(user_choice != 1 && user_choice != 2 && user_choice !=3);
        
        if (user_choice !=3)
        {
            printf("Enter the shift key: ");
            scanf("%d", &shift_key);
        }

        if (user_choice == 1)
        {
            encrypt(pass_phrase, shift_key);
        }
        else if (user_choice == 2)
        {
            decrypt(pass_phrase, shift_key);
        }
    }
    while (user_choice != 3);
}


//
//
//
void convertToUppercase(char pass_phrase[])
{
    for (int i = 0; i < strlen(pass_phrase); i++)
    {
        pass_phrase[i] = toupper(pass_phrase[i]);
    }
}


//
//
//
void encrypt(char pass_phrase[], int shift_key)
{
    printf("Enter the string to encrypt: ");
    scanf("%s", pass_phrase);
    convertToUppercase(pass_phrase);
    printf("Here is your encrypted string:\n");

    for (int i = 0; i < strlen(pass_phrase); i++)
    {
        if ((pass_phrase[i] + shift_key) >'Z' )
        {
            pass_phrase[i] = pass_phrase[i] + shift_key - 26;
        }
        else
        {
            pass_phrase[i] = pass_phrase[i] + shift_key;
        }
        printf("%c", pass_phrase[i]);
    }
    printf("\n");
}


//
//
//
void decrypt(char pass_phrase[], int shift_key)
{
    printf("Enter the string to decrypt: ");
    scanf("%s", pass_phrase);
    convertToUppercase(pass_phrase);
    printf("Here is your decrypted string:\n");

    for (int i = 0; i < strlen(pass_phrase); i++)
    {
        if ((pass_phrase[i] - shift_key) <'A' )
        {
            pass_phrase[i] = pass_phrase[i] - shift_key + 26;
        }
        else
        {
            pass_phrase[i] = pass_phrase[i] - shift_key;
        }
        printf("%c", pass_phrase[i]);
    }
    printf("\n");
}