/*
 * Time complexity O(n)
 */
#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 11

int arr[STACK_SIZE] = {0};
int count = 0;

_Bool isEmpty() {
	if (count == 0) {
		return 1;
	} else { 
		return 0;
	}
}

void top() {
	printf("\nItem on the top: %d\n", arr[0]);
}

void pop() {
	printf("\nItem popped: %d\n", arr[0]);
	for(int i = 0; i < count; i++ ) {
		arr[i] = arr[i+1];
	}
	count--;
}

void push(int num) {
	
	if (count < STACK_SIZE) {
		for (int i = count; i >= 0; i--) {
			arr[i] = arr[i-1];
		}
		arr[0] = num;
		count++;
	} else {
		printf("\nStack is full\n");
		exit(0);
	}
}

void print() {
	printf("\nPrinting elements of stack: ");
	for(int i = 0; i <= count - 1; i++) {
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
	top();
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
