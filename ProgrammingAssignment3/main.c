/*
	Evan Yang
	9-10-2025
*/

#include "musicManager.h"
#include "test.h";

int main()
{
	printf("Would you like to run test functions or go to the main menu?\n");
	printf("1) Run Tests\n");
	printf("2) Main Menu\n");
	printf("Please make your selection: ");

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
                testInsert();
                testDelete();
                testShuffle();
                break;
            case 2:
                system("cls");
                Node* head = NULL;
                showMenu(&head);
                break;
            default:
                isResponseValid = 0;
                printf("Not a valid selection. Please make a valid selection: ");
                break;
            }
        }
    }

	return 0;
}
