#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodeDLL 
{
	char* sent;
	struct nodeDLL* prev = NULL;
	struct nodeDLL* next = NULL;
};

void createDoubleLinkedList();

void printDoubleLinkedList();

void addToBeginDoubleLinkedList();

int isSentanceWithSecreteWord(char* sentance, char letter);

void secreteAllSentancesInDoubleLinkedList();

void deleteAllFromDoubleLinkedList();




