/*
    Author: Evan Yang
    Date: 8-26-2025
    Description: Reverses the given string using recursion.
*/

#include <stdio.h>

char *stringReverse (char *string, int startingIndex, int length);

int main()
{
    char string1[50] = "Hello world.";
    puts(string1);
    puts(stringReverse(string1, 0, -1));
    return 0;
}

char *stringReverse (char *string, int startingIndex, int length) 
{
    if(length == -1)
    {
        length = 0;
        while(string[length] != '\0')
        {
            length++;
        }
    }

    if(startingIndex < length / 2)
    {
        char temp = string[startingIndex];
        string[startingIndex] = string[(length - 1) - startingIndex];
        string[(length - 1) - startingIndex] = temp;
        return stringReverse(string, startingIndex + 1, length);
    }
    else
    {
        return string;
    }
}