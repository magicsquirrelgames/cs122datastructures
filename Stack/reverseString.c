#include "reverseString.h"

char *reverseString(char *string)
{
    Stack *stack = createStack();
    Data data;
    int index = 0;

    while(string[index] != '\0')
    {
        data.character = string[index];
        push(stack, data);
        index++;
    }

    index = 0;

    while(!isEmpty(*stack))
    {
        string[index] = pop(stack).character;
        index++;
    }

    return string;
}