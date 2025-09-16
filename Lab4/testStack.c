#include "stack.h"
#include "testStack.h"

// TEST CREATE STACK ===================================
void testCreateStack()
{
    Stack *stack = createStack();

    if(stack != NULL)
        printf("\033[0;32mStack created successfully.\033[0m\n");
    else
        printf("\033[0;31mStack was not created successfully.\033[0m\n");
}

// TEST CREATE NODE ===================================
void testCreateNode()
{
    StackNode *node = createNode(1.3);

    if(node != NULL)
    {
        if(node->data == 1.3)
            printf("\033[0;32mNode created successfully.\033[0m\n");
        else
            printf("\033[0;31mNode was created but does not contain the correct data.\033[0m\n");
    }
    else
    {
        printf("\033[0;31mNode was not created successfully.\033[0m\n");
    }
}

// TEST IS EMPTY ===================================
void testIsEmpty1()
{
    Stack *stack = createStack();

    if(isEmpty(stack))
        printf("\033[0;32mExpected 1. isEmpty() returned 1.\033[0m\n");
    else
        printf("\033[0;31mExpected 1. isEmpty() returned 0.\033[0m\n");
}

void testIsEmpty2()
{
    Stack *stack = createStack();
    push(stack, 1.2);
    push(stack ,3.5);
    push(stack, 8.3);

    printf("Expected 0. isEmpty() returned %d.\033[0m\n", isEmpty(stack));
}

// TEST PUSH ===================================
void testPush1()
{
    Stack *stack = createStack();
    if(push(stack, 1.1))
    { 

    }
    else
    {
        printf("push() on an empty stack failed.\033[0m\n");
    }
}

void testPush2()
{

}

// TEST POP ===================================
void testPop1()
{

}

void testPop2()
{

}

// TEST PEEK ===================================
void testPeek1()
{

}

void testPeek2()
{

}

// TEST PRINT STACK ===================================
void testPrintStack1()
{

}

void testPrintStack2()
{

}

// TEST PRINT FIRST ===================================
void testPrintFirst1()
{

}

void testPrintFirst2()
{

}