#include<stdlib.h>
#include<stdio.h>

struct Node {
        int data;
        struct Node *next;
};

int lengthOfList(struct Node *head);
void ReverseList(struct Node **head);
void DeleteNode(struct Node **head, int pos);
