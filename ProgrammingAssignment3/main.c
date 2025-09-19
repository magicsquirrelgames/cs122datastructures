/*
	Evan Yang
	9-10-2025

	NEED TO FINISH:
	store
	display
	insert
	delete
	edit
	sort
	rate
	play
	shuffle
	exit
*/

#include "musicManager.h"

int main()
{
	// create the head node
	Node* head = NULL;

	// open the input file
	FILE *inputFile;
	inputFile = fopen("musicPlayList.csv", "r");

	if (inputFile == NULL)
	{
		printf("ERROR: Input file could not be opened");
		return -1;
	}

	// open the output file
	FILE* outputFile;
	outputFile = fopen("test.csv", "w");

	if (outputFile == NULL)
	{
		printf("ERROR: Output file could not be opened");
		return -1;
	}

	/*
	Duration newDuration = { 3,35 };
	Record newRecord = { "Swift, Taylor","1989","Shake it Off","Pop",newDuration,12,3 };

	insertAtFront(&head, newRecord);
	*/

	load(&head, inputFile);
	store(head, outputFile);

	// show the menu
	showMenu(&head, inputFile, outputFile);
	return 0;
}
