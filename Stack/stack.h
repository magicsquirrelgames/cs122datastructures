#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char character;
} Data;

typedef struct node
{
    Data data;
    struct node *next;
} Node;

typedef struct stack
{
    Node* head;
}Stack;

Node *createNode(Data newData);
Stack *createStack();
int push(Stack *stack, Data newData);
Data pop(Stack *stack);
Data peek(Stack* stack);
int size(Stack *stack);
int isEmpty(Stack stack);
void printStack(Stack *stack);

#endif