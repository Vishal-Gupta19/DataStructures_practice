#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *head = NULL;
int capacity = 10;

Node* getNewNode(int data) {
	Node *temp = NULL;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int sizeOfQ() {
	int count = 0;
	Node *temp = head;
	while(temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

void addToQ(int data) {
	printf("\nAdding %d to queue\n", data);
	if (sizeOfQ() == capacity) {
		printf("\nQueue is full\n");
		exit(0);
	}
	Node *temp = getNewNode(data);
	temp->next = head;
	head = temp;
}

void removeFromQ() {
	printf("\nRemoving from queue\n");
	Node *temp = head;
	Node *temp2 = NULL;
	if (head == NULL) {
		printf("\nThere is no element in queue\n");
		exit(0);
	}
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	temp2 = temp;
	temp = temp->next;
	temp2->next = NULL;
	free(temp);
}

void frontElement() {
	int data = 0;
	Node *temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	data = temp->data;
	printf("\nElement at front of queue is %d\n", data);
}

void rearElement() {
	int data = 0;
	if (head == NULL) {
		printf("\nThere is no element in queue\n");
		exit(0);
	}
	data = head->data;
	printf("\nElement at rear of queue is %d\n", data);
}
	
void print() {
	printf("\nPrinting elements in queues: ");
	Node *temp = head;
	if (head == NULL) {
		printf("\nThere is no element in queue\n");
		exit(0);
	}
	while(temp != NULL) {
		printf("%d ", temp->data); 
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	printf("\nImplementing Queues using link-list\n");
	printf("\n==========================================\n");
	printf("\nEnter queue capacity:");
	scanf("%d", &capacity);
	
	printf("Size:%d\n", sizeOfQ());
	addToQ(1);
	print();
	addToQ(2);
	print();
	addToQ(3);
	print();
	frontElement();
	removeFromQ();
	print();
	printf("Size:%d\n", sizeOfQ());
	addToQ(4);
	print();
	addToQ(5);
	print();
	addToQ(6);
	print();

	
	return 0;
}
