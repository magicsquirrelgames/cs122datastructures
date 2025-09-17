/*
	Evan Yang
	9-10-2025
*/

#define _CRT_SECURE_NO_WARNINGS

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
	int timesPlayed;
	int rating;
	Duration duration;
}Record;

typedef struct node
{
	Record data;
	struct node* next;
	struct node* previous;
}Node;

void showMenu(Node** head, FILE* inFile, FILE* outFile);

Node* createNode(Record newData);
int insertAtFront(Node** head, Record newData);

Node* load(Node** head, FILE* inputFile);
void store(Node* head, FILE* outputFile);

void display();
void display(char* targetArtist);

void edit(Node* head, char* targetArtist, Record newData);
void rate(Node* head, char* targetTitle, int newRating);
void play(Node* head, char* targetTitle);
void exit(Node* head, FILE* outputFile);