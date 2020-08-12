#include<stdlib.h>
#include<stdio.h>

struct Node {
	int data;
	struct Node *next;
};

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
		if (temp != NULL) printf(" %d", temp->data);
	}

}

void PrintReverseNew(struct Node* head_ref, int n) 
{ 
	printf("printing in new style\n");
	int j = 0; 
        struct Node* current = head_ref; 
	while (current != NULL) { 
	     
	       for (int i = 0; i < 2 * (n - j); i++) 
	            printf(" "); 
	       printf("\r"); 
	       printf("%d", current->data); 
	       current = current->next; 
	       j++; 
      } 
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
	printf("How many numbers? ");
	scanf("%d", &n);
	printf("Enter numbers: \n");
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		//InsertAtBeg(&head, x);
		InsertAtEnd(&head, x);
	}

	printf("\nPrinting list:\n");
	Print(head);
	printf("\nPrinting list in reverse order:\n");
	PrintReverse(head);

	len = lengthOfList(head);
	printf("\n\nLength of List is %d\n", len);
	PrintReverseNew(head, len);
#if 0
	printf("\n\nInsert an element at a given position\n");
	printf("Enter position betwwen 1 and %d: \n", len);
	scanf("%d", &pos);
	printf("Enter number: \n");
	scanf("%d", &num);
	InsertAtPosition(head, num, pos);
	printf("Printing list:\n");
	Print(head);
#endif
	return 0;
}
