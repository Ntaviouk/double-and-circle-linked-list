#include "circleLinkedList.h"

typedef struct nodeCLL NODECLL;

NODECLL* head = NULL;

void addToCircleLinkedList(char* sentance)
{	
	NODECLL* tempNode = (NODECLL*)malloc(sizeof(NODECLL));
	tempNode->sentance = sentance;
	if (head == NULL)
	{
		head = tempNode;
		head->next = tempNode;
		return;
	}
	else
	{
		NODECLL* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = tempNode;
		tempNode->next = head;
		return;
	}
}

void printCircleLinkedList()
{
	if (head == NULL)
	{
		printf("no elements bro\n");
		return;
	}
	NODECLL* temp = head;
	while (temp)
	{
		printf("%s", temp->sentance);
		if (temp->next != head) printf(" -> ");
		temp = temp->next;
		if (temp == head)
		{
			printf("\n");
			return;
		}
	}
}


int countAmountOfWords(char* sentance)
{
	int counter = 1;
	char* ptr = sentance;
	while (*ptr != '\0')
	{
		if (*ptr == ' ') counter += 1;
		ptr++;
	}
	return counter;
}


void deleteSentacesWithLessThanFourWords()
{
	if (head == NULL)
	{
		printf("no elements\n");
		return;
	}
	NODECLL* start = NULL;
	if (countAmountOfWords(head->sentance) < 4)
	{
		start = head;
	}
	else
	{
		NODECLL* tempStart = head->next;
		while (tempStart != head)
		{
			if (countAmountOfWords(tempStart->sentance) <= 4)
			{
				start = tempStart;
				break;
			}
			tempStart = tempStart->next;
		}
		if (tempStart == head)
		{
			head->next = NULL;
			head = NULL;
			return;
		}
		else
		{
			head = start;
		}
	}
	NODECLL* temp = start;
	NODECLL* tempNext = temp->next;
	while (tempNext != head)
	{
		if (countAmountOfWords(tempNext->sentance) <= 4)
		{
			temp->next = tempNext;
			temp = temp->next;
			tempNext = temp->next;
			temp->next = head;
		}
		else
		{
			NODECLL* prev = tempNext;
			tempNext = tempNext->next;
			free(prev->sentance);
			prev->next = NULL;
			free(prev);
		}
	}
	if (temp == head) head->next = head;
}


void deleteAllFromCircleLinkedList()
{
	if (head == NULL) return;
	else
	{
		NODECLL* temp = head->next;
		while (temp)
		{
			NODECLL* tempForDelete = temp;
			temp = temp->next;
			free(tempForDelete->sentance);
			free(tempForDelete);
			if (temp == head) break;
		}
		free(temp->sentance);
		free(temp);
	}
}