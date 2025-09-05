/*
    Author: Evan Yang
    Date: 8-26-2025
    Description: Appends a source string onto the end of the given destination string.
*/

#include <stdio.h>

char *my_strcat (char *destination, const char *source);

int main()
{
    char string1[50] = "Hello world. ";
    const char string2[50] = "Goodbye world.";
    puts(string1);
    puts(string2);
    my_strcat(string1, string2);
    puts(string1);
    return 0;
}

char *my_strcat (char *destination, const char *source) 
{
    int destinationIndex = 0;
    int sourceIndex = 0;
    while(destination[destinationIndex] != '\0')
    {
        destinationIndex++;
    }
    while(source[sourceIndex] != '\0')
    {
        destination[destinationIndex] = source[sourceIndex];
        sourceIndex++;
        destinationIndex++;
    }
    return destination;
}