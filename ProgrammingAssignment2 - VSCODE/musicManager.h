#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record
{
	char artist[50];
	char album[50];
	char title[50];
	char genre[50];
	Duration duration;
	int timesPlayed;
	int rating;
}Record;

typedef struct node
{
	Record data;
	struct node *current;
	struct node* previous;
}Node;