#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum boolean
{
    FALSE, TRUE
} Boolean;

typedef struct contact
{
    char name[50];
    char phone[12];
    char email[50];
    char title[20];
 } Contact;

typedef struct node
{
    Contact data;
    struct node *pNext;
    struct node *pPrev;
} Node;

// Description: Allocates space for a Node on the heap and initializes 
// the Node with the information found in newData.
// Returns: The address of the start of the block of memory on the heap
// or NULL if no memory was allocated
Node * makeNode(Contact newData);

// Description: Uses makeNode () to allocate space for a new Node and
// inserts the new Node into the front of the list.
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise
Boolean insertContactAtFront(Node **pList, Contact newData);

// Description: Uses makeNode () to allocate space for a new Node and
// inserts the new Node into the list in
// alphabetic order ('a' - 'z') based on the name field
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise
Boolean insertContactInOrder(Node **pList, Contact newData);

// Description: Deletes a Contact in the list based on the name field;
// deletes the first occurrence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean deleteContact(Node **pList, Contact searchContact);

// Description: Edits a Contact in the list based on the name field;
// edits the first occurrence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean editContact(Node *pList, Contact searchContact);

// Description: Loads all Contact information from the given file, in
// alphabetic order, based on the name, into the list
// Returns: TRUE if all Contacts were loaded; FALSE otherwise
Boolean loadContacts(FILE *infile, Node **pList);

// Description: Stores all Contact information from the list into the
// given file
// Returns: TRUE if all Contacts were stored; FALSE otherwise
Boolean storeContacts(FILE *infile, Node *pList);

void showMenu();

int main()
{
    
    showMenu();
    return 0;
}

void showMenu()
{
    printf("===========================================\n");
    printf("Welcome to the Amazing Contact Manager 3000\n");
    printf("===========================================\n");
    printf("1) Add\n");
    printf("2) Remove\n");
    printf("3) Edit\n");
    printf("4) Print\n");
    printf("5) Store\n");
    printf("6) Load\n");
    printf("===========================================\n");
    printf("Please select a function: ");

    int response = 0;
    Boolean isResponseValid = FALSE;

    while(isResponseValid == FALSE)
    {
        scanf("%d", &response);
        isResponseValid = TRUE;
        switch(response)
        {
            case 1:
                printf("Please enter the name of the person you would like to add: \n");
                break;
            case 2:
                printf("ok\n");
                break;
            case 3:
                printf("ok\n");
                break;
            case 4:
                printf("ok\n");
                break;
            case 5:
                printf("ok\n");
                break;
            case 6:
                printf("ok\n");
                break;
            default:
                isResponseValid = FALSE;
                printf("Not a valid function. Please select a valid function: ");
                break;
        }
    }

    showMenu();
}

Node * makeNode(Contact newData)
{
    Node *node = malloc(sizeof(Node));

    if(node != NULL)
    {
        strcpy(node -> data.name, newData.name);
        strcpy(node -> data.phone, newData.phone);
        strcpy(node -> data.email, newData.email);
        strcpy(node -> data.title, newData.title);

        node->pNext = NULL;
        node->pPrev = NULL;
    }
    return node;
}

Boolean insertContactAtFront(Node **pList, Contact newData)
{
    Node *newNode = createNode(newData);

    if(newNode == NULL) return FALSE;

    // sets node.next to the node at the head pointer
    newNode->pNext = *pList;
    
    // sets the head pointer to point at the new node
    *pList = newNode;

    // makes the previous head pointer's node.previous to point at the new node
    newNode->pNext->pPrev = newNode;

    return TRUE;
}

Boolean insertContactInOrder(Node **pList, Contact newData)
{
    Node *newNode = createNode(newData);

    if(newNode == NULL) return 0;

    Node *current = *pList;

    while(current != NULL && current->pNext != NULL && strcmp(newData.name,current->data.name) > 0)
    {
        current = current->pNext;
    }

    if(current != NULL) // if the header is not null
    {
        if(strcmp(newData.name,current->data.name) > 0) // add after 
        {
            newNode->pNext = current->pNext;
            newNode->pPrev = &current;

            if(current->pNext != NULL) current->pNext->pPrev = &newNode;

            current->pNext = &newNode;
        }
        else // add before
        {
            newNode->pNext = &current;
            newNode->pPrev = current->pPrev;

            if(current->pPrev != NULL)
                current->pPrev->pNext = newNode;
            else
                *pList = newNode;

            current->pPrev = &newNode;
        }
    }
    else // if the header is null
    {
       *pList = newNode;
    }
}

Boolean deleteContact(Node **pList, Contact searchContact)
{
    // find the node with the same name
    Node *current = *pList;
    while(current != NULL && current->data.name != searchContact.name)
    {
        current = current->pNext;
    }

    // return false if none was found
    if(current == NULL) return FALSE;

    if(current->pNext != NULL) current->pNext->pPrev = current->pPrev;

    if(current->pPrev != NULL)
        current->pPrev->pNext = current->pNext;
    else
        *pList = current->pNext;

    return TRUE;
}

Boolean editContact(Node *pList, Contact searchContact)
{
    // find the node with the same name
    Node *current = pList;
    while(current != NULL && current->data.name != searchContact.name)
    {
        current = current->pNext;
    }

    // return false if none was found
    if(current == NULL) return FALSE;

    *current->data.name = searchContact.name;

    return TRUE;    
}

Boolean loadContacts(FILE *infile, Node **pList)
{
    char fileLine[132] = "";
    while (fgets(fileLine, 132, infile) != NULL)
    {
        Contact newData = {"","","",""};

        strcpy(newData.name, strtok(fileLine, ","));
        strcpy(newData.phone, strtok(NULL,","));
        strcpy(newData.email, strtok(NULL,","));
        strcpy(newData.title, strtok(NULL,","));

        Node *newNode = createNode();
    }
}

Boolean storeContacts(FILE *infile, Node *pList)
{
    Node *current = pList;
    while(current != NULL)
    {
        fprintf(infile, current->data.name);
        fprintf(infile, ",");
        fprintf(infile, current->data.phone);
        fprintf(infile, ",");
        fprintf(infile, current->data.email);
        fprintf(infile, ",");
        fprintf(infile, current->data.title);
        fprintf(infile, "\n");
    }
}

char *getLastName(char *name)
{
    char nameCopy = strcpy(nameCopy, name);
    char lastName[50] = "";
    char temp[50] = "";

    while(temp != NULL)
    {
        strcpy(lastName, temp);
        strcpy(temp, strtok(nameCopy, " "));
    }
}