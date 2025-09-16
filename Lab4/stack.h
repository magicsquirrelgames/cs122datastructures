#include <stdio.h>
#include <stdlib.h>

// STRUCTS
typedef struct stackNode
{
    double data;
    struct stackNode *next;
}StackNode;

typedef struct stack
{
    StackNode *head;
}Stack;

// FUNCTION PROTOTYPES
Stack *createStack();
StackNode *createNode(double newData);
int isEmpty(Stack *stack);
int push(Stack *stack, double newData);
void pop(Stack *stack);
double peek(Stack *stack);
void printStack(Stack *stack);
void printFirst(Stack *stack);