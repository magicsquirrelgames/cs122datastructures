/* comment */

#include "movies.h"

int recStrLen(const char* str)
{
    int count = 0;

    if (*str != '\0') //(str[0])
    {
        count += recStrLen(str + 1) + 1; // advance the pointer 1 element and recursively call again
    }

    return count;
}