/*
 * Time complexity O(1)
 */
#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 11

int arr[STACK_SIZE] = {0};
int top = -1;

_Bool isEmpty() {
        if (top == -1) {
                return 1;
        } else {
                return 0;
        }
}

void pop() {
        printf("\nItem popped: %d\n", arr[top]);
	top--;
}

void push(int num) {
	if (top == STACK_SIZE - 1) {
	       printf("\nStack is full\n");
	} else {	       
		top++;
		arr[top] = num;
	}
}

void print() {
        printf("\nPrinting elements of stack: ");
        for(int i = 0; i <= top; i++) {
                printf("%d  ", arr[i]);
        }
        printf("\n");
}

int main() {
        printf("\nImplementing stack using Array");
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
        push(5);
        print();
        push(6);
        print();
        push(7);
        print();
        push(8);
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
