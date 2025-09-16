#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct stack
{
    Node* head;
}Stack;

// DECLERATION
Node *createNode(int newData);
int push(Stack *stack, int newData);
int pop(Stack *stack);
int peek(Stack* stack);
int size(Stack *stack);

int main()
{
    Stack *stack;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("%d",size(stack));

    return 0;
}

// CREATE NODE
Node *createNode(int newData)
{
    Node *newNode = malloc(sizeof(Node));

    if(newNode != NULL)
    {
        newNode->data = newData;
    }

    return newNode;
}

// PUSH
int push(Stack *stack, int newData)
{
    Node *newNode = createNode(newData);

    if(newNode == NULL) return -1;
    if(stack->head != NULL) newNode->next = stack->head;

    stack->head = newNode;

    return 1;
}

// POP
int pop(Stack* stack)
{
    if(stack->head == NULL)
    {
        return -1;
    }
    else
    {
        int data = stack->head->data;
        stack->head = stack->head->next;
        return data;
    }
}

// PEEK
int peek(Stack *stack)
{
    if(stack->head == NULL) 
        return -1;
    else
        return stack->head->data;
}

// SIZE
int size(Stack *stack)
{
    int count;
    Node *current = stack->head;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}