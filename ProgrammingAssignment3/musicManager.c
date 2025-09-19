/*
	Evan Yang
	9-10-2025
*/

#include "musicManager.h"

// SHOW MENU
void showMenu(Node** head, FILE* inputFile, FILE* outputFile)
{
    // clear the console
    //system("cls");

    // print the menu
    printf("===========================================\n");
    printf("Welcome to the Amazing Music Manager 3000\n");
    printf("===========================================\n");
    printf("1) Load\n");
    printf("2) Store\n");
    printf("3) Display\n");
    printf("4) Insert\n");
    printf("5) Delete\n");
    printf("6) Edit\n");
    printf("7) Sort\n");
    printf("8) Rate\n");
    printf("9) Play\n");
    printf("10) Shuffle\n");
    printf("11) Exit\n");
    printf("===========================================\n");
    printf("Please select a function: ");

    int response = 0;
    int isResponseValid = 0;

    while (isResponseValid == 0)
    {
        response = scanf("%d", &response);
        isResponseValid = 1;
        switch (response)
        {
            case 1:
                printf("You selected: Load\n");
                break;
            case 2:
                printf("You selected: Store\n");
                break;
            case 3:
                printf("You selected: Display\n");
                break;
            case 4:
                printf("You selected: Insert\n");
                break;
            case 5:
                printf("You selected: Delete\n");
                break;
            case 6:
                printf("You selected: Edit\n");
                break;
            case 7:
                printf("You selected: Sort\n");
                break;
            case 8:
                printf("You selected: Rate\n");
                break;
            case 9:
                printf("You selected: Play\n");
                break;
            case 10:
                printf("You selected: Shuffle\n");
                break;
            case 11:
                printf("You selected: Exit\n");
                break;
            default:
                isResponseValid = 0;
                printf("Not a valid function. Please select a valid function: ");
                break;
        }
    }

    showMenu(head, inputFile, outputFile);
}

// CREATE NODE
Node* createNode(Record newData)
{
    Node* newNode = malloc(sizeof(Node));

    if (newNode != NULL)
    {
        strcpy(newNode->data.artist, newData.artist);
        strcpy(newNode->data.album, newData.album);
        strcpy(newNode->data.title, newData.title);
        strcpy(newNode->data.genre, newData.genre);

        newNode->data.timesPlayed = newData.timesPlayed;
        newNode->data.rating = newData.rating;

        newNode->data.duration = newData.duration;
    }
    return newNode;
}

// INSERT AT FRONT
int insertAtFront(Node** head, Record newData)
{
    // create with a new node
    Node* newNode = createNode(newData);
    if (newNode == NULL) return 0;
    
    // set the head node's previous pointer to the new node
    if (*head != NULL && (*head)->next != NULL) (*head)->next->previous = newNode;

    // set the new node's next pointer to the head node
    newNode->next = *head;

    // set the head pointer to the new node
    *head = newNode;

    return 1;
}

// LOAD FROM THE FILE TO THE LIST
Node* load(Node** head, FILE* inputFile)
{
    // repeat for each line in the file
    char line[100];
    while (fgets(line, 100, inputFile) != NULL)
    {
        // copy data from the file to a record
        Record newRecord;
        strcpy(newRecord.artist, strtok(line, ","));
        strcpy(newRecord.album, strtok(NULL, ","));
        strcpy(newRecord.title, strtok(NULL, ","));
        strcpy(newRecord.genre, strtok(NULL, ","));
        strcpy(newRecord.album, strtok(NULL, ","));

        // save the duration string to be parsed later
        char durationString[10];
        strcpy(durationString, strtok(NULL, ","));

        newRecord.timesPlayed = atoi(strtok(NULL, ","));
        newRecord.rating = atoi(strtok(NULL, ",")); // ERROR HERE

        // parse the duration string once the rest of the data has been parsed
        Duration newDuration;
        newDuration.minutes = atoi(strtok(durationString, ":"));
        newDuration.seconds = atoi(strtok(NULL, ":"));

        newRecord.duration = newDuration;

        // add that record as a node in the linked list
        insertAtFront(head, newRecord);
    }

    return *head;
}

// STORE THE LIST TO THE FILE
void store(Node* head, FILE* outputFile)
{
    Node* current = head;
    if (current != NULL)
    {
        fprintf(outputFile, current->data.artist);
        fprintf(outputFile, ",");
        fprintf(outputFile, current->data.album);
        fprintf(outputFile, ",");
        fprintf(outputFile, current->data.title);
        fprintf(outputFile, ",");
        fprintf(outputFile, current->data.genre);
        fprintf(outputFile, ",");
        fprintf(outputFile, "%d", current->data.duration.minutes);
        fprintf(outputFile, ":");
        fprintf(outputFile, "%d", current->data.duration.seconds);
        fprintf(outputFile, ",");
        fprintf(outputFile, "%d", current->data.timesPlayed);
        fprintf(outputFile, ",");
        fprintf(outputFile, "%d", current->data.rating);
        fprintf(outputFile, "\n");
    }
}