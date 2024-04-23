#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodeCLL
{
	char* sentance;
	struct nodeCLL* next = NULL;
};


void addToCircleLinkedList(char* sentance);

void printCircleLinkedList();

int countAmountOfWords(char* sentance);

void deleteSentacesWithLessThanFourWords();

void deleteAllFromCircleLinkedList();