#include <stdio.h>

typedef struct stackNode
{
    double data;
    struct stackNode *next;
}StackNode;

typedef struct stack
{
    StackNode *head;
}Stack;

int isEmpty(Stack *stack);
int push(Stack *stack, double newData);
void pop(Stack *stack);

int main()
{
    return 0;
}