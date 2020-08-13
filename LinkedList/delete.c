#include<stdlib.h>
#include<stdio.h>
#include"def.h"

void DeleteNode(struct Node **head, int pos) {
        int len = 0;
        struct Node *temp = *head;

        if (pos == 1) {
                *head = temp->next;
                free(temp);
                return;
        }

        len = lengthOfList(*head);
        if (pos > len || pos < 1) {
                printf("Invalid position\n");
                return;
        }

        for (int i = 0; i < (pos - 2); i++) {
                temp = temp->next;
        }

        struct Node *temp2 = NULL;
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
}
