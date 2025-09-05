/*
    Author: Evan Yang
    Date: 8-26-2025
    Description: Combines two strings then sorts them using the big beautiful bubble sort.
*/

#include <stdio.h>
#include <ctype.h>

char *combineAndSort(char *string1, char * string2, char *combined);
char *bubbleSort(char *string);
char *toLowerCase(char *string);

int main()
{
    char string1[50] = "Hello world. ";
    char string2[50] = "Goodbye world.";
    char combined[100] = {0};
    combineAndSort(string1, string2, combined);
    puts(combined);
    return 0;
}

char *combineAndSort(char *string1, char *string2, char *combined)
{
    int index;
    int indexCombined;
    while(string1[index] != '\0')
    {
        combined[indexCombined] = string1[index];
        index++;
        indexCombined++;
    }
    index = 0;
    while(string1[index] != '\0')
    {
        combined[indexCombined] = string1[index];
        index++;
        indexCombined++;
    }

    return bubbleSort(combined);
}

char *bubbleSort(char *string)
{
    toLowerCase(string);
    int length;
    while(string[length] != '\0')
    {
        length++;
    }

    int madeChange = 1;
    while(madeChange != 0)
    {
        madeChange = 0;
        for(int i = 0; i < length - 1; i++)
        {
            if(string[i] > string[i+1])
            {
                char temp = string[i];
                string[i] = string[i+1];
                string[i+1] = temp;
                madeChange = 1;
            }
        }
    }

    return string;
}

char *toLowerCase(char *string) 
{
    for (int i = 0; string[i] != '\0'; i++) 
    {
        string[i] = tolower(string[i]);
    }

    return string;
}