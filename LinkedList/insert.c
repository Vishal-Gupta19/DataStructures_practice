#include<stdlib.h>
#include<stdio.h>
#include"def.h"

int lengthOfList(struct Node *head);

void Print(struct Node *head) {
	struct Node *temp = head;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void PrintReverse(struct Node *head) {
	struct Node *temp = head;
	int count = 0;

#if 0
	// Recursive method
	if (temp == NULL) return;
	PrintReverse(temp->next);
	printf("%d ", temp->data);
#endif

	count = lengthOfList(head);
	int i;
	for (i = count; i > 0; i--) {
		int j = 0;
		temp = head;
		while(j != i-1) {
			temp = temp->next;
			j++;
		}
		if (temp != NULL) printf("%d ", temp->data);
	}
	printf("\n");
}

int lengthOfList(struct Node *head) {
	int len = 0;
	struct Node *temp = head;
	while(temp != NULL) {
		temp = temp->next;
		len++;
	}
	return len;
}

void InsertAtBeg(struct Node **head, int x) {
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp != NULL) {
		temp->data = x;
		temp->next = NULL;
		if (*head != NULL) temp->next = *head;
		*head = temp;
	}
}

void InsertAtEnd(struct Node **head, int x) {
	struct Node *tmp = NULL;
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

	if (temp != NULL) {
		temp->data = x;
		temp->next = NULL;
		if (*head == NULL) {
			*head = temp;
			return;
		}
		tmp = *head;
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = temp;
	}
}

void InsertAtPosition(struct Node *head, int num, int pos) {
	struct Node *tmp = head;
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

	if (pos > lengthOfList(head) + 1 || pos < 1) {
		printf("Invalid position given\n");
		free(temp);
		return;
	}

	if (temp != NULL) {
		temp->data = num;
		temp->next = NULL;
		for (int i = 1; i < pos - 1; i++) {
			tmp = tmp->next;
		}
		temp->next = tmp->next;
		tmp->next = temp;
	}

}

int main() {
	struct Node *head;
	int len = 0;
	int num = 0;
	int pos = 0;
	int n, i, x;

	head = NULL;
	printf("\nHow many numbers do you want ot insert? - ");
	scanf("%d", &n);
	printf("Enter numbers: \n");
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		//InsertAtBeg(&head, x);
		InsertAtEnd(&head, x);
	}

	printf("\nPrinting list: ");
	Print(head);
	printf("Printing list in reverse order: ");
	PrintReverse(head);

	printf("\n\nInsert an element at a given position. . .");
	printf("\nEnter position to insert: ");
	scanf("%d", &pos);
	printf("Enter number: ");
	scanf("%d", &num);
	InsertAtPosition(head, num, pos);
	printf("\nPrinting list: ");
	Print(head);

	printf("\n\nEnter position of the node to delete: ");
	scanf("%d", &pos);
	DeleteNode(&head, pos);
	printf("Printing list: ");
	Print(head);

	printf("\n\nReversing the list . . .");
	ReverseList(&head);
	printf("\nPrinting list: ");
	Print(head);

	return 0;
}
