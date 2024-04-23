#include "doubleLinkedList.h"
#include "circleLinkedList.h"
#include "general.h"


typedef struct nodeDLL NODEDLL;

NODEDLL* head = NULL;



void createDoubleLinkedList()
{
	NODEDLL* temp_node = (NODEDLL*)malloc(sizeof(NODEDLL));
	char* temp = (char*)malloc(50);
	printf("enter sent : ");
	int tempIndex = 0;
	while (getchar() != '\n');
	char tempChar = getchar();
	temp[tempIndex++] = tempChar;
	while (tempChar != '\n' && tempIndex < 50)
	{
		tempChar = getchar();
		temp[tempIndex++] = tempChar;
	}
	temp[--tempIndex] = '\0';
	temp_node->sent = temp;

	if (head == NULL)
	{
		head = temp_node;
		head->prev = NULL;
		head->next = NULL;
	}
	else
	{
		NODEDLL* tempNode = head;
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = temp_node;
		temp_node->prev = tempNode;
		temp_node->next = NULL;
	}
}


void printDoubleLinkedList()
{
	NODEDLL* tempNode = head;
	if (tempNode == NULL)
	{
		printf("no elements\n");
		return;
	}
	else
	{
		while (tempNode != NULL)
		{
			printf("%s", tempNode->sent);
			if (tempNode->next != NULL)
			{
				printf(" -> ");
			}
			tempNode = tempNode->next;
		}
	}
}


void addToBeginDoubleLinkedList()
{
	NODEDLL* tempNode = (NODEDLL*)malloc(sizeof(NODEDLL));
	char* tempSent = (char*)malloc(50);
	int tempCounter = 0;
	printf("enter sentence : ");
	while (getchar() != '\n');

	char tempSentChar = getchar();
	while (tempSentChar != '\n' && tempCounter < 50)
	{
		*(tempSent + tempCounter) = tempSentChar;
		tempSentChar = getchar();
		tempCounter++;
	}
	tempSent[tempCounter] = '\0';
	tempNode->sent = tempSent;

	if (head == NULL)
	{
		tempNode->next = NULL;
		tempNode->prev = NULL;
		head = tempNode;
		return;
	}
	else
	{
		tempNode->next = head;
		head->prev = tempNode;
		tempNode->prev = NULL;
		head = tempNode;
	}
}

int isSentanceWithSecreteWord(char* sentance, char letter)
{
	if (*sentance == letter or *sentance == letter - 32) return 1;
	char* ptr = sentance;
	while (*ptr != '\0')
	{
		if (*ptr == ' ' && (*(ptr + 1) == letter || *(ptr + 1) == letter - 32)) return 1;
		ptr++;
	}
	return 0;
}

void secreteAllSentancesInDoubleLinkedList()
{
	if (head == NULL)
	{
		printf("no elements\n");
		return;
	}
	else
	{
		char tempChar;
		printf("enter char to delete sentance : ");
		while (getchar() != '\n');
		scanf_s("%c", &tempChar);
		NODEDLL* temp = head;
		while (temp != NULL)
		{
			if (isSentanceWithSecreteWord(temp->sent, tempChar))
			{
				secreteWord(temp->sent, tempChar);
				addToCircleLinkedList(temp->sent);
				if (temp == head)
				{
					NODEDLL* tempHead = temp;
					head = temp->next;	
					if (head == NULL) break;
					head->prev = NULL;
					//free(tempHead->sent);
					tempHead = NULL;
					free(tempHead);
				}
				else
				{
					NODEDLL* tempNode = temp;
					temp->prev->next = temp->next;
					temp = temp->next;
					if (temp == NULL) break;
					temp->prev = tempNode->prev;
					//free(tempNode->sent);
					tempNode = NULL;
					free(tempNode);
				}
			}	
			else
			{
				temp = temp->next;
			}
		}
	}
}

void deleteAllFromDoubleLinkedList()
{
	NODEDLL* temp = head;
	NODEDLL* next;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->sent);
		free(temp);
		temp = next;
	}
	head = NULL;
}

