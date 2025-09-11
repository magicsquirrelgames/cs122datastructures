#ifndef LINKED_LIST_H

#define LINKED_LIST_H
#define _CRT_SECURE_NO_WARNINGS

// inlcludes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs
typedef struct movie
{
    char title[30];
    int year;
} Movie;

typedef struct node
{
    Movie data;
    struct node *next;
} Node;

// function declarations
void initList(Node **list);
void printList(Node *list);
int insertAtFront(Node **list, Movie newMovie);
int insertInOrder(Node **list, Movie newMovie);
Node *createNode(Movie newMovie);
Movie deleteAtFront(Node **list);

#endif

// main
int main()
{
    printf("size of node: %lu bytes\n", sizeof(Node));

    Movie movie1 = {"Alien", 1979};
    Movie movie2 = {"The Matrix", 1999};
    Movie movie3 = {"Cars", 2006};
    Movie temp = {"",-1};
    Node *head = NULL;

    initList(&head);

    insertAtFront(&head, movie1);
    insertAtFront(&head, movie2);

    printList(head);

    temp = deleteAtFront(&head);
    printf("Data returned: %s\n", temp.title);
    
    printList(head);

    return 0;
}

// function definitions
Node *createNode(Movie newMovie)
{
    Node *pMem = malloc(sizeof(Node)); // allocates 42 bytes for the node

    if(pMem != NULL)
    {
        pMem -> next = NULL;
        pMem -> data.year = newMovie.year;
        strcpy(pMem -> data.title, newMovie.title);
    }
    return pMem;
}

// we must use double pointer to prevent operating on a pointer that is uninitialized
void initList(Node **list)
{
    *list = NULL;
}

int insertAtFront(Node **list, Movie newMovie)
{
    Node *tempPointer = createNode(newMovie);

    if(tempPointer == NULL) return 0;

    tempPointer->next = *list;
    *list = tempPointer;

    return 1;
}

void printList(Node *list)
{
    Node *temp = list;
    while(temp != NULL)
    {
        printf("(Title: %s, Year: %d), ", temp->data.title, temp->data.year);
        temp = temp->next;
    }

    putchar('\n');
}

Movie deleteAtFront(Node **list)
{
    Node *current = *list;
    Movie data = current->data;

    *list = current->next;
    free(current);

    return data;
}

int insertInOrder(Node **list, Movie newMovie)
{
    Node *newNode = createNode(newMovie);

    if(newNode == NULL) return 0;

    Node *current = *list;
    Node *previous = NULL;

    while(current != NULL && strcmp(newMovie.title,current->data.title) > 0)
    {
        previous = current;
        current = current->next;
    }

    if(current == NULL)
    {
        if(previous == NULL) // list is empty
        {
            *list = newNode;
        }
        else // insert at the end
        {
            previous->next = newNode;
        }
    }
    else
    {
        if(previous == NULL) // list has 1 element (insert in front of it)
        {
            newNode->next = current;
            *list = newNode;
        }
        else // insert in the middle (insert behind current)
        {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    return 1;
}