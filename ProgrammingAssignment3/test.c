/*
    Evan Yang
    9-23-2025
*/

#include "test.h"
#include "musicManager.h"

void testInsert()
{
	system("cls");
	printf("To test the insert function, please attempt to input \"Perry, Katey\", \"Witness\", \"Chained to the Rhythm\", \"pop\", \"4:36\", \"-1\", and \"6\".\n");
	printf("The function should not allow you to enter -1 for times played or 6 for rating.\n");
	
	printf("Press enter to start the test.\n");
	while (getchar() != '\n');

	Node* head = NULL;
	insert(&head);

    if (strcmp(head->data.title, "Chained to the Rhythm") == 0)
    {
        printf("\033[1;32mRecord successfully inserted.\033[0m\n");
    }
    else
    {
        printf("\033[1;31mRecord inserted does not match expected values.\033[0m\n");
    }

    printf("Press enter to start the next test.\n");
    while (getchar() != '\n');
}

void testDelete()
{
	system("cls");
	printf("To test the delete function, please attempt to delete the song \"Chained to the Rhythm\".\n");
	printf("The function should find this song and delete it from the list.\n");

	printf("Press enter to start the test.\n");
	while (getchar() != '\n');

	Duration newDuration = { 4,36 };
	Record newRecord = { "Perry, Katy", "Witness", "Chained to the Rhythm", "pop", newDuration, 3, 5 };

	Node* head = NULL;
	insertAtFront(&head, newRecord);

	delete(&head);

	if (head == NULL)
	{
		printf("\033[1;32mRecord successfully deleted.\033[0m\n");
	}
	else
	{
		printf("\033[1;31mRecord was not successfully deleted.\033[0m\n");
	}

    printf("Press enter to start the next test.\n");
    while (getchar() != '\n');
}

void testShuffle()
{
	system("cls");
	printf("The shuffle function does not natively support passing a set play order to it.\n");
	printf("To test the shuffle function, a duplicate of the algorithm will be made and the order will be passed to it.\n");
	printf("The expected order is \"Schism\", \"Toxicity\", \"Back to School (Mini Maggit)\".\n");

	printf("Press enter to start the test.\n");
	while (getchar() != '\n');

	Duration duration1 = { 3,39 };
	Record newRecord1 = { "System of a Down", "Toxicity", "Toxicity", "heavy-metal", duration1, 20, 5 };

	Duration duration2 = { 3,58 };
	Record newRecord2 = { "Deftones", "White Pony", "Back to School (Mini Maggit)", "alt-metal", duration2, 32, 5 };

	Duration duration3 = { 6,44 };
	Record newRecord3 = { "TOOL", "Lateralus", "Schism", "prog-metal", duration1, 17, 5 };

	Node* head = NULL;
	insertAtFront(&head, newRecord3);
	insertAtFront(&head, newRecord2);
	insertAtFront(&head, newRecord1);

    int shuffledIndexes[10] = { 3,1,2 };
    int currentIndex = 0;
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

        Sleep(2000);
    }

    printf("All tests complete. Press enter to exit.\n");
    while (getchar() != '\n');
    exit(0);
}