#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *head = NULL;
Node* getNewNode(int data); 

void pop() {
	printf("\nPopping the data: %d\n", head->data);
	Node *temp = head;
	head = head->next;
	free(temp);
}

void push(int data) {
	printf("\nPushing %d into stack\n", data);
	Node *temp = getNewNode(data);
	temp->next = head;
	head = temp;
}

_Bool isEmpty() {
	if (head == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void print() {
	printf("\nPrinting the data in stack: "); 
	Node *temp = head;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Node* getNewNode(int data) {
	Node *temp = NULL;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int main() {
        printf("\nImplementing stack using Linked List");
        printf("\n=====================================");
        printf("\nIs stack empty? - %s\n", isEmpty()? "yes" : "no");
        push(1);
        print();
        printf("\nIs stack empty? - %s\n", isEmpty()? "yes" : "no");
        push(2);
        print();
        push(3);
        print();
        push(4);
        print();
        pop();
        print();
        print();
        push(5);
        print();
        push(6);
        print();
        push(7);
        print();
        push(8);
        print();
	pop();
        print();
        push(9);
        print();
        push(10);
        print();
        push(11);
        print();
        push(12);
        print();
        push(13);
        print();


	return 0;
}
