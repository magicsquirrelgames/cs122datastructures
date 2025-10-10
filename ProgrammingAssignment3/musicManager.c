/*
	Evan Yang
	9-10-2025
*/

#include "musicManager.h"

// SHOW MENU ========================================================
void showMenu(Node** head)
{
    // clear the console
    system("cls");

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

    char response[100] = "";
    int selection = 0;
    int isResponseValid = 0;

    while (isResponseValid == 0)
    {
        isResponseValid = 1;

        if (fgets(response, sizeof(response), stdin) == NULL)
        {
            isResponseValid = 0;
            printf("Not a valid input. Please enter again: ");
        }

        if (isResponseValid)
        {
            if (sscanf(response, "%d", &selection) != 1)
            {
                isResponseValid = 0;
                printf("Not a valid input. Please enter a number: ");
            }
        }
        
        if (isResponseValid)
        {
            switch (selection)
            {
            case 1:
                system("cls");
                printf("You selected: 1) Load.\n");
                load(head);
                returnToMenu(head);
                break;
            case 2:
                system("cls");
                printf("You selected: 2) Store.\n");
                store(*head);
                returnToMenu(head);
                break;
            case 3:
                system("cls");
                printf("You selected: 3) Display.\n");
                display(*head);
                returnToMenu(head);
                break;
            case 4:
                system("cls");
                printf("You selected: 4) Insert.\n");
                insert(head);
                returnToMenu(head);
                break;
            case 5:
                system("cls");
                printf("You selected: 5) Delete.\n");
                delete(head);
                returnToMenu(head);
                break;
            case 6:
                system("cls");
                printf("You selected: 6) Edit.\n");
                edit(*head);
                returnToMenu(head);
                break;
            case 7:
                system("cls");
                printf("You selected: 7) Sort.\n");
                sort(*head);
                returnToMenu(head);
                break;
            case 8:
                system("cls");
                printf("You selected: 8) Rate.\n");
                rate(*head);
                returnToMenu(head);
                break;
            case 9:
                system("cls");
                printf("You selected: 9) Play.\n");
                play(*head);
                returnToMenu(head);
                break;
            case 10:
                system("cls");
                printf("You selected: 10) Shuffle.\n");
                shuffle(*head);
                returnToMenu(head);
                break;
            case 11:
                system("cls");
                printf("You selected: 11) Exit.\n");
                exitProgram(*head);
                returnToMenu(head);
                break;
            default:
                isResponseValid = 0;
                printf("Not a valid selection. Please make a valid selection: ");
                break;
            }
        }
    }
}

// RETURN TO MENU ========================================================
void returnToMenu(Node** head)
{
    printf("Press enter to return to the menu.\n");
    while (getchar() != '\n');
    showMenu(head);
}

// CREATE NODE ========================================================
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

// INSERT AT FRONT ========================================================
int insertAtFront(Node** head, Record newData)
{
    // create a new node
    Node* newNode = createNode(newData);
    if (newNode == NULL) return 0;
    
    // set the head node's previous pointer to the new node
    if (*head != NULL) (*head)->previous = newNode;

    // set the new node's next pointer to the head node
    newNode->next = *head;

    // set the head pointer to the new node
    *head = newNode;

    return 1;
}

// could not get insert at back to work for some reason :(
// INSERT AT BACK ========================================================
int insertAtBack(Node** head, Record newData)
{
    // create a new node
    Node* newNode = createNode(newData);
    if (newNode == NULL) return 0;

    // if the list is empty, add to the front
    if (*head == NULL)
    {
        *head = newNode;
        return 1;
    }

    // otherwise navigate to the end of the list
    Node* current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->previous = current;

    return 1;
}

// LOAD FROM THE FILE TO THE LIST ========================================================
int size(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

// LOAD FROM THE FILE TO THE LIST ========================================================
void load(Node** head)
{
    // open the input file
    FILE* inputFile;
    inputFile = fopen("musicPlayList.csv", "r");

    if (inputFile == NULL)
    {
        printf("ERROR: Input file could not be opened");
        return -1;
    }

    // repeat for each line in the file
    char line[100];
    while (fgets(line, 100, inputFile) != NULL)
    {
        // copy data from the file to a record
        Record newRecord;

        // if the first character is a " use a different delimeter for the first element
        if (line[0] == '"')
        {
            strcpy(newRecord.artist, strtok(line, "\""));
        }
        else
        {
            strcpy(newRecord.artist, strtok(line, ","));
        }

        strcpy(newRecord.album, strtok(NULL, ","));
        strcpy(newRecord.title, strtok(NULL, ","));
        strcpy(newRecord.genre, strtok(NULL, ","));

        // save the duration string to be parsed later
        char durationString[10];
        strcpy(durationString, strtok(NULL, ","));

        newRecord.timesPlayed = atoi(strtok(NULL, ","));
        newRecord.rating = atoi(strtok(NULL, ","));

        // parse the duration string once the rest of the data has been parsed
        Duration newDuration;
        newDuration.minutes = atoi(strtok(durationString, ":"));
        newDuration.seconds = atoi(strtok(NULL, ":"));

        newRecord.duration = newDuration;

        // add that record as a node in the linked list
        insertAtFront(head, newRecord);
    }

    fclose(inputFile);
    printf("Successfully loaded data from musicPlayList.csv.\n");
}

// STORE THE LIST TO THE FILE ========================================================
void store(Node* head)
{
    if (head == NULL)
    {
        printf("No data to store. Please select the \"load\" function to load in music data from a .csv file.\n");
        return;
    }

    // open the output file
    FILE* outputFile;
    outputFile = fopen("musicPlayList.csv", "w");

    if (outputFile == NULL)
    {
        printf("ERROR: Output file could not be opened");
        return -1;
    }

    Node* current = head;
    while (current != NULL)
    {
        // determine if the artist includes a comma
        char artistCopy[50] = "";
        strcpy(artistCopy, current->data.artist);

        int lastAndFirst = 0;
        if(strcmp(current->data.artist, strtok(artistCopy, ",")) != 0)
        {
            lastAndFirst = 1;
        }

        // if it does, print out quotation marks around it
        if (lastAndFirst)
        {
            fprintf(outputFile, "\"");
            fprintf(outputFile, current->data.artist);
            fprintf(outputFile, "\"");
        }
        else
        {
            fprintf(outputFile, current->data.artist);
        }

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

        current = current->next;
    }

    fclose(outputFile);
    printf("Successfully updated musicPlayList.csv.\n");
}

// DISPLAY RECORDS TO THE SCREEN ========================================================
void display(Node *head)
{
    Node* current = head;
    if (current == NULL)
    {
        printf("No data to display. Please select the \"load\" function to load in music data from a .csv file.\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("Artist: ");
            printf(current->data.artist);
            printf("\n");

            printf("Album: ");
            printf(current->data.album);
            printf("\n");

            printf("Title: ");
            printf(current->data.title);
            printf("\n");

            printf("Genre: ");
            printf(current->data.genre);
            printf("\n");

            printf("Duration: ");
            printf("%d", current->data.duration.minutes);
            printf(":");
            printf("%d", current->data.duration.seconds);
            printf("\n");

            printf("Times Played: ");
            printf("%d", current->data.timesPlayed);
            printf("\n");

            printf("Rating: ");
            printf("%d", current->data.rating);
            printf("\n");

            printf("\n");

            current = current->next;
        }
    }
}

// INSERT A NEW RECORD ========================================================
void insert(Node** head)
{
    printf("To insert a new record, you will need to provide:\n");
    printf("Artist, Album, Title, Genre, Duration, Times Played, and Rating.\n");

    printf("What would you like to insert into \"artist\"?: ");

    char response[100] = "";
    int numberResponse = 0;
    Record newRecord;

    // enter the artist
    fgets(response, sizeof(response), stdin);
    while (response[0] == '\0' || response[0] == '\n')
    {
        printf("You must enter something into the \"artist\" field. Please enter again: ");
        fgets(response, sizeof(response), stdin);
    }
    strcpy(newRecord.artist, strtok(response, "\n"));

    // enter the album
    printf("What would you like to insert into \"album\"?: ");
    fgets(response, sizeof(response), stdin);
    while (response[0] == '\0' || response[0] == '\n')
    {
        printf("You must enter something into the \"album\" field. Please enter again: ");
        fgets(response, sizeof(response), stdin);
    }
    strcpy(newRecord.album, strtok(response, "\n"));

    // enter a title
    printf("What would you like to insert into \"title\"?: ");
    fgets(response, sizeof(response), stdin);
    while (response[0] == '\0' || response[0] == '\n')
    {
        printf("You must enter something into the \"title\" field. Please enter again: ");
        fgets(response, sizeof(response), stdin);
    }
    strcpy(newRecord.title, strtok(response, "\n"));

    // enter a genre
    printf("What would you like to insert into \"genre\"?: ");
    fgets(response, sizeof(response), stdin);
    while (response[0] == '\0' || response[0] == '\n')
    {
        printf("You must enter something into the \"genre\" field. Please enter again: ");
        fgets(response, sizeof(response), stdin);
    }
    strcpy(newRecord.genre, strtok(response, "\n"));

    // enter a duration
    printf("What would you like to insert into \"minutes\"?: ");
    fgets(response, sizeof(response), stdin);
    while (sscanf(response, "%d", &numberResponse) != 1)
    {
        printf("Please enter a number for the \"minutes\" field: ");
        fgets(response, sizeof(response), stdin);
    }
    newRecord.duration.minutes = numberResponse;
    printf("What would you like to insert into \"seconds\"?: ");
    fgets(response, sizeof(response), stdin);
    while (sscanf(response, "%d", &numberResponse) != 1)
    {
        printf("Please enter a number for the \"seconds\" field: ");
        fgets(response, sizeof(response), stdin);
    }
    newRecord.duration.seconds = numberResponse;

    // enter times played
    printf("What would you like to insert into \"times played\"?: ");
    fgets(response, sizeof(response), stdin);
    while (sscanf(response, "%d", &numberResponse) != 1 || numberResponse < 0)
    {
        printf("Please enter a number greater than or equal to 0 for the \"times played\" field: ");
        fgets(response, sizeof(response), stdin);
    }
    newRecord.timesPlayed = numberResponse;

    // enter rating
    printf("What would you like to insert into \"rating\"?: ");
    fgets(response, sizeof(response), stdin);
    while (sscanf(response, "%d", &numberResponse) != 1 || numberResponse < 1 || numberResponse > 5)
    {
        printf("Please enter a number between 1 and 5 for the \"rating\" field: ");
        fgets(response, sizeof(response), stdin);
    }
    newRecord.rating = numberResponse;

    // insert the new record into the thing
    insertAtFront(head, newRecord);
}

// DELETE ========================================================
void delete(Node** head)
{
    if (*head == NULL)
    {
        printf("No data to delete. Please select the \"load\" function to load in music data from a .csv file.\n");
    }

    char response[100] = "";
    char responseNoNewLine[100] = "";

    // get the title of the record the user wants to delete
    printf("Please enter the title of the record you would like to delete: ");
    fgets(response, sizeof(response), stdin);
    while (response[0] == '\0' || response[0] == '\n')
    {
        printf("The title cannot be empty. Please enter again: ");
        fgets(response, sizeof(response), stdin);
    }
    strcpy(responseNoNewLine, strtok(response, "\n"));

    // find the record that matches that title
    Node* current = *head;
    Node* previous = NULL;
    int foundRecord = 0;
    while (current != NULL && !foundRecord)
    {
        if (strcmp(current->data.title, responseNoNewLine) == 0)
        {
            foundRecord = 1;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    // delete the record from the list
    if (!foundRecord)
    {
        printf("A record with that title could not be found.\n");
        return;
    }
    else
    {
        if (previous == NULL) // delete the first element
        {
            *head = current->next;
            if (current->next != NULL) current->next->previous = NULL;
            free(current);
        }
        else // delete an element at the beginning or the end
        {
            previous->next = current->next;
            if (current->next != NULL) current->next->previous = previous;
            free(current);
        }

        printf("Record was deleted.\n");
        return;
    }
}

// EDIT THE GIVEN RECORD ========================================================
void edit(Node* head)
{
    if (head == NULL)
    {
        printf("No data to edit. Please select the \"load\" function to load in music data from a .csv file.\n");
        return;
    }

    char response[100] = "";
    char responseNoNewLine[100] = "";
    int isResponseValid = 0;

    Node* current = head;
    Node* matchingRecords = NULL;

    printf("Please enter the name of the artist whose records you would like to edit: ");
    fgets(response, sizeof(response), stdin);
    if(response[0] != '\n') strcpy(responseNoNewLine, strtok(response, "\n"));

    while (!isResponseValid)
    {
        current = head;
        while (current != NULL)
        {
            if (strcmp(current->data.artist, responseNoNewLine) == 0)
            {
                insertAtFront(&matchingRecords, current->data);
            }
            current = current->next;
        }

        // if no matching records were found, return
        if (matchingRecords == NULL)
        {
            printf("Could not find any records belonging to that artist. Please enter again: ");
            fgets(response, sizeof(response), stdin);
            if (response[0] != '\n') strcpy(responseNoNewLine, strtok(response, "\n"));
        }
        else
        {
            isResponseValid = 1;
        }
    }

    current = matchingRecords;

    // if there are more than 1 records by an artist, ask the user which one they want to edit
    if (matchingRecords->next != NULL)
    {
        printf("There are multiple records by that artist. They are: \n");
        while (current != NULL)
        {
            printf(current->data.title);
            printf("\n");
            current = current->next;
        }
        printf("Please enter the name of the record you would like to edit: ");
        fgets(response, sizeof(response), stdin);
        if (response[0] != '\n') strcpy(responseNoNewLine, strtok(response, "\n"));

        isResponseValid = 0;
        while (!isResponseValid)
        {
            current = matchingRecords;
            while (current != NULL && !isResponseValid)
            {
                if (strcmp(responseNoNewLine, current->data.title) == 0)
                {
                    isResponseValid = 1;
                }
                else
                {
                    current = current->next;
                }
            }

            if (!isResponseValid)
            {
                printf("Could not find a record matching that title. Please enter again: ");
                fgets(response, sizeof(response), stdin);
                if (response[0] != '\n') strcpy(responseNoNewLine, strtok(response, "\n"));
            }
        }
    }

    // find the chosen title in the list
    char chosenTitle[100] = "";
    strcpy(chosenTitle, current->data.title);

    current = head;
    while (strcmp(current->data.title, chosenTitle) != 0)
    {
        current = current->next;
    }

    // display the user's options for what to edit
    int finished = 0;
    while (!finished)
    {
        system("cls");
        printf("What data would you like to edit? Type \"exit\" to finish editing the record.\n");
        printf("1) Artist\n");
        printf("2) Album\n");
        printf("3) Title\n");
        printf("4) Genre\n");
        printf("5) Duration\n");
        printf("6) Times Played\n");
        printf("7) Rating\n");
        printf("Please enter the number corresponding to the data you want to edit: ");

        fgets(response, sizeof(response), stdin);

        if (strcmp(response, "exit\n") == 0)
        {
            printf("The record has been edited.\n");
            finished = 1;
        }

        if (!finished)
        {
            isResponseValid = 0;
            int selection = 0;
            while (!isResponseValid)
            {
                if (sscanf(response, "%d", &selection) != 1)
                {
                    isResponseValid = 0;
                    printf("Not a valid input. Please enter a number: ");
                }
                else
                {
                    isResponseValid = 1;
                }
            }

            // allow the user to edit different parts of the data
            switch (selection)
            {
            case 1: // artist
                printf("You selected: 1) Artist.\n");
                printf("What would you like to insert into \"artist\"?: ");
                fgets(response, sizeof(response), stdin);
                while (response[0] == '\0' || response[0] == '\n')
                {
                    printf("You must enter something into the \"artist\" field. Please enter again: ");
                    fgets(response, sizeof(response), stdin);
                }
                strcpy(current->data.artist, strtok(response, "\n"));
                break;
            case 2: // album
                printf("You selected: 2) Album.\n");
                printf("What would you like to insert into \"album\"?: ");
                fgets(response, sizeof(response), stdin);
                while (response[0] == '\0' || response[0] == '\n')
                {
                    printf("You must enter something into the \"album\" field. Please enter again: ");
                    fgets(response, sizeof(response), stdin);
                }
                strcpy(current->data.album, strtok(response, "\n"));
                break;
            case 3: // title
                printf("You selected: 3) Title.\n");
                printf("What would you like to insert into \"title\"?: ");
                fgets(response, sizeof(response), stdin);
                while (response[0] == '\0' || response[0] == '\n')
                {
                    printf("You must enter something into the \"title\" field. Please enter again: ");
                    fgets(response, sizeof(response), stdin);
                }
                strcpy(current->data.title, strtok(response, "\n"));
                break;
            case 4: // genre
                printf("You selected: 4) Genre.\n");
                printf("What would you like to insert into \"genre\"?: ");
                fgets(response, sizeof(response), stdin);
                while (response[0] == '\0' || response[0] == '\n')
                {
                    printf("You must enter something into the \"genre\" field. Please enter again: ");
                    fgets(response, sizeof(response), stdin);
                }
                strcpy(current->data.genre, strtok(response, "\n"));
                break;
            case 5:// duration
                printf("You selected: 5) Duration.\n");
                printf("What would you like to insert into \"minutes\"?: ");
                fgets(response, sizeof(response), stdin);
                while (sscanf(response, "%d", &selection) != 1)
                {
                    printf("Please enter a number for the \"minutes\" field: ");
                    fgets(response, sizeof(response), stdin);
                }
                current->data.duration.minutes = selection;
                printf("What would you like to insert into \"seconds\"?: ");
                fgets(response, sizeof(response), stdin);
                while (sscanf(response, "%d", &selection) != 1)
                {
                    printf("Please enter a number for the \"seconds\" field: ");
                    fgets(response, sizeof(response), stdin);
                }
                current->data.duration.seconds = selection;
                break;
            case 6: // times played
                printf("You selected: 6) Times Played.\n");
                printf("What would you like to insert into \"times played\"?: ");
                fgets(response, sizeof(response), stdin);
                while (sscanf(response, "%d", &selection) != 1 || selection < 0)
                {
                    printf("Please enter a number greater than or equal to 0 for the \"times played\" field: ");
                    fgets(response, sizeof(response), stdin);
                }
                current->data.timesPlayed = selection;
                break;
            case 7: // rating
                printf("You selected: 7) Rating.\n");
                printf("What would you like to insert into \"rating\"?: ");
                fgets(response, sizeof(response), stdin);
                while (sscanf(response, "%d", &selection) != 1 || selection < 1 || selection > 5)
                {
                    printf("Please enter a number between 1 and 5 for the \"rating\" field: ");
                    fgets(response, sizeof(response), stdin);
                }
                current->data.rating = selection;
                break;
            default:
                printf("Not a valid selection. Please make a valid selection: ");
                break;
            }
        }
    }
}

// SORT ========================================================
void sort(Node* head)
{
    // make sure the list is not empty
    if (head == NULL)
    {
        printf("There are no records to sort. Please select the \"load\" function to load in music data from a .csv file.\n");
        return;
    }

    // print out the options
    printf("How would you like to sort the list?\n");
    printf("1) Sort based on artist (A-Z)\n");
    printf("2) Sort based on album title (A-Z)\n");
    printf("3) Sort based on rating (1-5)\n");
    printf("4) Sort based on times played (largest-smallest)\n");
    printf("Please make your selection: ");

    // get the players selection
    int isResponseValid = 0;
    int selection = 0;
    char response[100] = "";
    while (!isResponseValid)
    {
        fgets(response, sizeof(response), stdin);
        if (sscanf(response, "%d", &selection) != 1)
        {
            isResponseValid = 0;
            printf("Not a valid input. Please enter a number: ");
        }
        else
        {
            isResponseValid = 1;
        }

        // sort based on the players selection
        int didSomething = 1;
        Node* current = head;
        switch (selection)
        {
        case 1: // sort by artist
            while (didSomething)
            {
                didSomething = 0;
                current = head;
                while (current->next != NULL)
                {
                    if (strcmp(current->data.artist, current->next->data.artist) > 0)
                    {
                        swap(current, current->next);
                        didSomething = 1;
                    }
                    current = current->next;
                }
            }
            break;
        case 2: // sort by album
            while (didSomething)
            {
                didSomething = 0;
                current = head;
                while (current->next != NULL)
                {
                    if (strcmp(current->data.album, current->next->data.album) > 0)
                    {
                        swap(current, current->next);
                        didSomething = 1;
                    }
                    current = current->next;
                }
            }
            break;
        case 3: // sort by rating
            while (didSomething)
            {
                didSomething = 0;
                current = head;
                while (current->next != NULL)
                {
                    if (current->data.rating > current->next->data.rating)
                    {
                        swap(current, current->next);
                        didSomething = 1;
                    }
                    current = current->next;
                }
            }
            break;
        case 4: // sort by times played
            while (didSomething)
            {
                didSomething = 0;
                current = head;
                while (current->next != NULL)
                {
                    if (current->data.timesPlayed < current->next->data.timesPlayed)
                    {
                        swap(current, current->next);
                        didSomething = 1;
                    }
                    current = current->next;
                }
            }
            break;
        default:
            printf("Not a valid selection. Please enter a valid selection: ");
            break;
        }

        printf("Array was sorted.\n");
    }
}

void swap(Node* node1, Node* node2)
{
    Record temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// RATE A RECORD ========================================================
void rate(Node* head)
{
    // make sure the list is not empty
    if (head == NULL)
    {
        printf("There are no records available to rate. Please select the \"load\" function to load in music data from a .csv file.\n");
        return;
    }

    // get the title of the record the user wants to rate
    char response[100] = "";
    char responseNoNewline[100] = "";

    printf("Please enter the title of the record you would like to rate: ");
    fgets(response, sizeof(response), stdin);
    if(response[0] != '\n') strcpy(responseNoNewline, strtok(response, "\n"));

    // validate the response and find the correct record
    Node* current = head;
    int isResponseValid = 0;
    while (!isResponseValid)
    {
        current = head;
        while (current != NULL && !isResponseValid)
        {
            if (strcmp(responseNoNewline, current->data.title) == 0)
            {
                isResponseValid = 1;
            }
            else
            {
                current = current->next;
            }
        }

        if (!isResponseValid)
        {
            printf("Could not find a record matching that title. Please enter again: ");
            fgets(response, sizeof(response), stdin);
            if (response[0] != '\n') strcpy(responseNoNewline, strtok(response, "\n"));
        }
    }

    // get the rating the user wants to give the record
    printf("How would you like to rate ");
    if(current != NULL) printf(current->data.title);
    printf("? (1-5): ");

    fgets(response, sizeof(response), stdin);

    // validate that rating
    int rating = 0;
    while (sscanf(response, "%d", &rating) != 1 || rating < 1 || rating > 5)
    {
        printf("Not a valid rating. Please input a number from 1 to 5: ");
        fgets(response, sizeof(response), stdin);
    }

    // set the rating
    if (current != NULL) current->data.rating = rating;
    printf("Rating has been updated.\n");
}

// PLAY THE PLAYLIST ========================================================
void play(Node* head)
{
    // make sure the list is not empty
    if (head == NULL)
    {
        printf("There are no records available to play. Please select the \"load\" function to load in music data from a .csv file.\n");
        return;
    }

    // get the title of the record the user wants to rate
    char response[100] = "";
    char responseNoNewline[100] = "";

    printf("Please enter the title of the record you would like to start playing at: ");
    fgets(response, sizeof(response), stdin);
    if(response[0] != '\n') strcpy(responseNoNewline, strtok(response, "\n"));

    // validate the response and find the correct record
    Node* current = head;
    int isResponseValid = 0;
    while (!isResponseValid)
    {
        current = head;
        while (current != NULL && !isResponseValid)
        {
            if (strcmp(responseNoNewline, current->data.title) == 0)
            {
                isResponseValid = 1;
            }
            else
            {
                current = current->next;
            }
        }

        if (!isResponseValid)
        {
            printf("Could not find a record matching that title. Please enter again: ");
            fgets(response, sizeof(response), stdin);
            if (response[0] != '\n') strcpy(responseNoNewline, strtok(response, "\n"));
        }
    }

    // print out the records in sequence with delay
    while (current != NULL)
    {
        system("cls");

        printf("Now playing: ");
        printf(current->data.title);
        printf("\n");

        printf("Artist: ");
        printf(current->data.artist);
        printf("\n");

        printf("Album: ");
        printf(current->data.album);
        printf("\n");

        printf("Title: ");
        printf(current->data.title);
        printf("\n");

        printf("Genre: ");
        printf(current->data.genre);
        printf("\n");

        printf("Duration: ");
        printf("%d", current->data.duration.minutes);
        printf(":");
        printf("%d", current->data.duration.seconds);
        printf("\n");

        printf("Times Played: ");
        printf("%d", current->data.timesPlayed);
        printf("\n");

        printf("Rating: ");
        printf("%d", current->data.rating);
        printf("\n");

        current->data.timesPlayed++;

        current = current->next;

        Sleep(2000);
    }

    system("cls");
    printf("End of playlist.\n");
}

// SHUFFLE ========================================================
void shuffle(Node* head)
{
    // make sure the list is not empty
    if (head == NULL)
    {
        printf("There are no records available to shuffle. Please select the \"load\" function to load in music data from a .csv file.\n");
        return;
    }

    printf("Shuffling...\n");

    // create an array of 100 indexes
    int indexes[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        indexes[i] = i;
    }

    // shuffle those indexes into another array within the size of the list
    int shuffledIndexes[100] = { 0 };
    int currentIndex = 0;
    while (shuffledIndexes[size(head) - 1] == 0)
    {
        // generate a random value between 1 and the size of the list
        srand(time(NULL));
        int randomIndex = (rand() % size(head)) + 1;

        // if the index has not already been used, add it to the shuffled list and remove it from the index array
        if (indexes[randomIndex] != 0)
        {
            shuffledIndexes[currentIndex] = indexes[randomIndex];
            indexes[randomIndex] = 0;
            currentIndex++;
        }
    }

    // play the songs in shuffled order, moving both forward and back between nodes
    currentIndex = 0;
    Node* current = head;
    for (int i = 0; i < shuffledIndexes[currentIndex] - 1; i++)
    {
        current = current->next;
    }
    while (currentIndex < size(head))
    {
        system("cls");

        printf("Now playing: ");
        printf(current->data.title);
        printf("\n");

        printf("Artist: ");
        printf(current->data.artist);
        printf("\n");

        printf("Album: ");
        printf(current->data.album);
        printf("\n");

        printf("Title: ");
        printf(current->data.title);
        printf("\n");

        printf("Genre: ");
        printf(current->data.genre);
        printf("\n");

        printf("Duration: ");
        printf("%d", current->data.duration.minutes);
        printf(":");
        printf("%d", current->data.duration.seconds);
        printf("\n");

        printf("Times Played: ");
        printf("%d", current->data.timesPlayed);
        printf("\n");

        printf("Rating: ");
        printf("%d", current->data.rating);
        printf("\n");

        current->data.timesPlayed++;

        if (shuffledIndexes[currentIndex] < shuffledIndexes[currentIndex + 1]) // move forward
        {
            for (int i = 0; i < shuffledIndexes[currentIndex + 1] - shuffledIndexes[currentIndex]; i++)
            {
                current = current->next;
            }
        }
        else // move backwards
        {
            for (int i = 0; i < shuffledIndexes[currentIndex] - shuffledIndexes[currentIndex + 1]; i++)
            {
                current = current->previous;
            }
        }
        currentIndex++;

        /* single link implementation
        current = head;
        for (int i = 0; i < shuffledIndexes[currentIndex] - 1; i++)
        {
            current = current->next;
        }
        */

        Sleep(2000);
    }

    system("cls");
    printf("End of shuffle.\n");
}

// EXIT ========================================================
void exitProgram(Node* head)
{
    if (head == NULL)
    {
        printf("The current playlist does not contain any data.");
        printf("Exiting will overwrite musicPlayList.csv with no data.");
    }

    printf("Are you sure you want to exit? (enter y or n): ");

    char response[100] = "";
    fgets(response, sizeof(response), stdin);
    while (response[0] != 'y' && response[0] != 'n')
    {
        printf("Please enter y or n: ");
        fgets(response, sizeof(response), stdin);
    }

    if (response[0] == 'y')
    {
        store(head);
        printf("Goodbye!\n");
        exit(0);
    }
}