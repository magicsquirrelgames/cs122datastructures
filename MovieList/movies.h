/* Header files are attatched to .c files and contain structs, enums, and includes
that my need to be used in multiple .c files in the project. */

#ifndef MOVIES_H // guard code
#define MOVIES_H

#include <stdio.h> // printf(), scanf(), fprint(), fgets(), fputs(), fscanf()
#include <string.h> // strcpy(), strcat(), strcmp(), strlen(), strtok()
#include <stdlib.h> // atoi(), atof()

typedef struct movie
{
    char title[30];
    int year; 
} Movie;

// enumerated types

// function declarations - function prototypes

int recStrLen(const char *str);

#endif