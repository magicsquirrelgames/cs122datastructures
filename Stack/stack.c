#include "stack.h"

// CREATE NODE
Node *createNode(Data newData)
{
    Node *newNode = malloc(sizeof(Node));

    if(newNode != NULL)
    {
        newNode->data = newData;
    }

    return newNode;
}

// CREATE STACK
Stack *createStack()
{
    Stack *stack = malloc(sizeof(Stack));
    return stack;
}

// PUSH
int push(Stack *stack, Data newData)
{
    Node *newNode = createNode(newData);

    if(newNode == NULL) return -1;
    if(stack->head != NULL) newNode->next = stack->head;

    stack->head = newNode;

    return 1;
}

// POP
Data pop(Stack* stack)
{
    Node* nodeToDelete = stack->head;

    Data data = nodeToDelete->data;
    stack->head = stack->head->next;

    free(nodeToDelete);

    return data;
}

// PEEK
Data peek(Stack *stack)
{
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

// IS EMPTY
int isEmpty(Stack stack)
{
    return stack.head == NULL;
}

// PRINT STACK
void printStack(Stack *stack)
{
    printf("[");
    Node *current = stack->head;
    while(current != NULL)
    {
        printf("%c", current->data.character);
        if(current->next != NULL)
        {
            printf(",");
        }
        current = current->next;
    }
    printf("]\n");
}