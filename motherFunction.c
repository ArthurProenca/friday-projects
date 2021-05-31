/*
    Este programa possui o intuíto de reproduzir as principais funções-mãe em C.
    @author: Arthur Proença, aka Artth_
    @date: 30-05-2021
    gcc mFunctions.o main.o -o main
*/
#include <stdio.h>
#include <stdlib.h>
//#include "motherFunctions.h"

signed int samstr(signed char *str)
{
    size_t i;
    for (i = 0; str[i] != '\0'; i++)
    {
    }
    return i;
}

/*
    @explain: This functions atributes to p the adress of str, increments it to the end of str and sums to the end of src.
    @explain: By this way, the adress of str receives str + src.
*/
signed char *cstr(signed char *str, const signed char *src)
{
    signed char *walker = str;

    while (*walker)
    {
        ++walker;
    }
    while ((*walker++ = *src++))
    {
    }
    return str;
}

signed int cmpstr(signed char *str, signed char *str2)
{
    size_t i;
    signed int contains = 0;
    if (samstr(str) == samstr(str2))
    {
        for (i = 0; i < samstr(str); i++)
        {
            if (str[i] == str2[i])
            {
                contains++;
            }
        }
    }
    else if (samstr(str) < samstr(str2))
    {
        return -1;
    }

    return contains / samstr(str) == 1 ? 0 : 1;
}

void menu()
{
    size_t i;
    signed int option = 0;
    signed char str[144], *str2;
    while (option != 42)
    {
        printf("\nOption: ");
        printf("\n--- Menu --- \n1 - strlen function \n2 - strcat \n3 - strcmp\n42 - exit program\nOption: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:

            printf("\nRunning strlen 'identity'... ");
            printf("\nPlease, type a string to evaluate the size (max 32): ");
            scanf("%s", str);
            printf("\nSize of string %s is %d!", str, samstr(str));
            break;

        case 2:
            printf("\nRunning strcat 'identity'... ");
            printf("\nPlease, type a word to concatenate with 'UwU': ");
            scanf("%s", str);
            printf("\nThe strings concatenated are: %s", cstr(str, "uwu"));
            break;

        case 3:
            printf("\nRunning strcmp 'identity'... ");
            printf("\nPlease, type a word to compair with 'test': ");
            scanf("%s", str);
            printf("\nThe word %s are %s to 'test'", str, (cmpstr(str, "test") == 0 ? "equal" : "not equal"));
            break;
        default:
            printf("\nInvalid option.");
        }
        system("clear||cls");
    }
}

int main()
{
    printf("\nThis algorithm wants to create the main 'mother-functions' of C/C++.");
    printf("\nPlease, select an option from menu: ");
    menu();
}
