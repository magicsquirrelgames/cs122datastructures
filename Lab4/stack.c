#include "stack.h"

// CREATE STACK ===================================
Stack *createStack()
{
    Stack *newStack = malloc(sizeof(Stack));
    return newStack;
}

// CREATE NODE ===================================
StackNode *createNode(double newData)
{
    StackNode *newNode = malloc(sizeof(StackNode));

    if(newNode != NULL)
    {
        newNode->data = newData;
    }

    return newNode;
}

// IS EMPTY ===================================
int isEmpty(Stack *stack)
{
    if(stack == NULL || stack->head == NULL)
        return 1;
    else
        return 0;
}

// PUSH ===================================
int push(Stack *stack, double newData)
{
    StackNode *newNode = createNode(newData);
    if(newNode == NULL) return 0;

    if(stack != NULL)
    {
        if(!isEmpty(stack))
        {
            newNode->next = stack->head;
        } 
        stack->head = newNode;
        return 1;
    }
    
    return 0;
}

// POP ===================================
void pop(Stack *stack)
{
    if(isEmpty(stack)) return;

    StackNode *nodeToFree = stack->head;
    stack->head = stack->head->next;

    free(nodeToFree);
}

// PEEK ===================================
double peek(Stack *stack)
{
    if(isEmpty(stack)) return 0;
    
    return stack->head->data;
}

// PRINT STACK ===================================
void printStack(Stack *stack)
{
    printf("[");
    
    StackNode* current = stack->head;
    while(current != NULL)
    {
        printf("%lf", current->data);
        if(current->next != NULL)
        {
            printf(",");
        }
        current = current->next;
    }

    printf("]\n");
}

// PRINT FIRST ===================================
void printFirst(Stack *stack)
{
    if(isEmpty(stack))
        printf("Stack is empty./n");
    else
        printf("%lf", stack->head->data);
}