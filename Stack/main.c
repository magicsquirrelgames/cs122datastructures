// HOW TO RUN CODE
// gcc main.c stack.c reverseString.c -o stack
// ./stack

#include "stack.h"
#include "reverseString.h"

int main()
{
    Stack *stack = createStack();

    char string[50] = "cat";
    printf("String before reverse: %s\n", string);

    reverseString(string);

    printf("String after reverse: %s\n", string);

    return 0;
}