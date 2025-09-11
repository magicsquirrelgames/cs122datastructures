// dynamic memory: memory that is allocated on the heap instead of the callstack
// dynamic data structure: a data structure that utilizes dynamic memory
// memory leak: memory that is allocated on the heap that has no pointer to it
// dangling pointer: a pointer pointing to a location in the heap that is unalocated
// defensive programming: checking values to make sure a runtime error cannot occur
// string vs. character array: strings are terminated by a null character

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
} Node;

Node* createNode(int data);
int insertAtFront(Node** head, int data);
int insertAtback(Node** head, int data);
int insertInorder(Node** head, int data);

int deleteFront(Node** head);
int deleteBack(Node** head);
int deleteAll(Node** head, int data);

Node* reverseList(Node* head);

void printList(Node* head);
void printListRec(Node* current);

int main()
{
    return 0;
}

// CREATE NODE
Node* createNode(int data)
{
    Node *node = malloc(sizeof(Node));

    if(node != NULL)
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

// INSERT AT FRONT
int insertAtFront(Node** head, int data)
{
    Node *node = createNode(data);
    if(node == NULL) return 0;

    node->next = *head;
    *head = node;

    return 1;
}

// INSERT AT BACK
int insertAtback(Node** head, int data)
{
    Node* current = *head;
    if(current == NULL) return insertAtFront(head, data);

    while(current->next != NULL)
    {
        current = current->next;
    }

    Node *node = createNode(data);
    if(node == NULL) return 0;

    current->next = node;

    return 1;
}

// INSERT IN ORDER
int insertInOrder(Node** head, int data)
{
    Node *current = *head;
    if(current == NULL || current->data >= data)
    {
        return insertAtFront(head, data);
    }

    Node* node = makeNode(data);
    if(node == NULL) return 0;

    while(current->next != NULL)
    {
        if(current->next->data > data)
        {
            node->next = current->next;
            current->next = node;
            return 1;
        }
        else
        {
            current = current->next;
        }
    }

    current->next = node;
    return 1;
}

// DELETE FRONT
int deleteFront(Node** head)
{
    if(head == NULL) return 0;

    Node* temp = *head;

    (*head) = temp->next;
    free(temp);
    return 1;
}

// DELETE BACK
int deleteBack(Node** head)
{
    if(head == NULL) return 0;

    Node* current = *head;
    Node* previous = NULL;
    while(current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    free(current);
    return 1;
}

Node* reverseList(Node* head)
{
    Node *previous = NULL;
    Node *current = NULL;
    Node *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }

    return previous;
}

// PRINT THE LIST
void printList(Node* head)
{
    while(head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

// PRINT THE LIST RECURSIVELY
void printListRec(Node* current)
{
    if(current == NULL) return;

    printf("%d\n", current->data);
    printListRec(current->next);
}