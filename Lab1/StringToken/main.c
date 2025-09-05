/*
    Author: Evan Yang
    Date: 8-26-2025
    Description: Reverses the given string using recursion.
*/

#include <stdio.h>

char *myStrTok(char *string, const char* delim);
int includesChar(char *string, char character);

char *myStrTok(char *string, const char* delim)
{
    static char *pToken;
    if(string != NULL)
    {
        int length;
        while(!includesChar(delim, string[length]))
        {
            string[0];
            length++;
        }
    }
    else
    {

    }
}

int includesChar(char *string, char character)
{
    int includes = 0;
    int index;
    while(string[index] != '\0')
    {
        if(character == string[index])
        {
            includes = 1;
        }
    }
}