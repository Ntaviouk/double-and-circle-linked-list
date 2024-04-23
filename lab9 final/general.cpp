#include "general.h"
#include "doubleLinkedList.h"
#include "circleLinkedList.h"

void secreteWord(char* sentance, char letter)
{
	char* ptr = sentance;
	if (*ptr == letter || *ptr == letter - 32)
	{
		while (*ptr != ' ' && *ptr != '\0')
		{
			*(ptr++) = '#';
		}
	}

	while (*ptr != '\0')
	{
		if (*ptr == ' ' && (*(ptr + 1) == letter || *(ptr + 1) == letter - 32))
		{
			while (*(ptr + 1) != ' ' && *(ptr + 1) != '\0')
			{
				ptr++;
				*ptr = '#';
			}
		}
		ptr++;
	}
}

void mainFunc()
{
	int choice;
	while (1)
	{
		printf("\n****\n");
		printf("0 - create\n");
		printf("1 - print\n");
		printf("2 - add to the beginning\n");
		printf("3 - secrete all\n");
		printf("4 - print circle linked list \n");
		printf("5 - delete all sentance where more than 4 words \n");
		printf("your choice : ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0:
			createDoubleLinkedList();
			break;
		case 1:
			printDoubleLinkedList();
			break;
		case 2:
			addToBeginDoubleLinkedList();
			break;
		case 3:
			secreteAllSentancesInDoubleLinkedList();
			break;
		case 4:
			printCircleLinkedList();
			break;
		case 5:
			deleteSentacesWithLessThanFourWords();
			break;
		default:
			printf("\ngg\n");
			return;
		}
	}
}