/*
	Evan Yang
	9-10-2025
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

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
	struct node* next;
	struct node* previous;
}Node;

void showMenu(Node** head);
void returnToMenu(Node** head);

Node* createNode(Record newData);
int insertAtFront(Node** head, Record newData);
int insertAtBack(Node** head, Record newData);
int size(Node* head);

void load(Node** head);
void store(Node* head);
void display(Node* head);
void insert(Node** head);
void delete(Node** head);
void edit(Node* head);
void sort(Node* head);
void swap(Node* node1, Node* node2);
void rate(Node* head);
void play(Node* head);
void shuffle(Node* head);
void exitProgram(Node* head);