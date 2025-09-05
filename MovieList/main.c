/*
    Author: Evan Yang
    Date: 8-22-2025
    Description: This application will read and parse a .csv file with movie information,
    allow the user to edit the information and store t back to the .csv file.
*/

#define _CRT_SEC_NO_WARNINGS

#include "movies.h"

int main(int argc, char *argv[])
{
    // open the csv file
    FILE * inputStream = fopen("movies.csv", "r");
    char record[50] = "";
    Movie moviesList[50] = {{.title = "", .year = -1}};
    int lineCount;

    char* str = "cat";
    printf("Length: %d\n", recStrLen(str));

    if(inputStream != NULL)
    {
        puts("opened file successfully.");

        while(fgets(record, 50, inputStream) != NULL) // fgets returns NULL when there is nothing left to read
        {
            puts(record); // prints to console

            strcpy(moviesList[lineCount].title, strtok(record, ",")); // copies first token to title
            moviesList[lineCount].year = atoi(strtok(NULL, "\n")); // copies and converts second token to year (int)
            
            lineCount++; // increment line count
        }
        fclose(inputStream);
    }

    return 0;
}
