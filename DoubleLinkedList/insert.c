#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node * head = NULL;

Node* GetNewNode(int data) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;

}

void PrintList() {
	Node *temp = head;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void PrintListReverse() {
	Node *temp = head;
	if (temp == NULL) return;
	while(temp->next != NULL) {
		temp = temp->next;
	}

	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
}

void InsertAtHead(int data) {
	Node *temp = GetNewNode(data);

	if (head == NULL) {
		head = temp;
		return;
	}

	head->prev = temp;
	temp->next = head;
	head = temp;
}

void InsertAtTail(int data) {
	Node *temp = GetNewNode(data);

	if (head == NULL) {
		head = temp;
		return;
	}

	Node *temp2 = head;
	while(temp2->next != NULL) {
		temp2 = temp2->next;
	}
	temp2->next = temp;
	temp->prev = temp2;
}


int main() {

	int count = 0, data = 0;
	printf("\nHow many numbers do you want to add? - ");
	scanf("%d", &count);
	printf("Enter numbers to add in list: \n");
	for (int i = 0; i < count; i++) {
		scanf("%d", &data);
		//InsertAtHead(data);
		InsertAtTail(data);
	}
	
	printf("\nPrinting list: ");
	PrintList();
	printf("\nPrinting list in reverse: ");
	PrintListReverse();
	printf("\n");
	return 0;
}
