#include<stdlib.h>
#include<stdio.h>
#include"def.h"

void ReverseList(struct Node **head) {
        struct Node *temp = NULL, *prev = NULL, *next = NULL;

        temp = *head;

        while(temp != NULL) {
                next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
        }
        *head = prev;
}

// TODO
struct Node* ReverseListRecursive(struct Node *head) {
        if (head->next == NULL) {
                return head;
        }

        struct Node *prev = head;
        prev = ReverseListRecursive(head->next);

        head->next = prev;
        prev->next = NULL;

        return head;
}
#if 0
int main() {
	return 0;
}
#endif
