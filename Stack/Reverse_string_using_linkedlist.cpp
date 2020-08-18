#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *head = NULL;

Node* getNewNode(int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void print() {
	cout << "\nPrinting values in Linked list: ";
	Node *temp = head;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void reverseLinkedList() {
	if (head == NULL) return;
	cout << "\nReversing a linked-list using Stack\n";
	stack<struct Node*> S;
	Node *temp = head;
	while(temp != NULL) {
		S.push(temp);
		temp = temp->next;
	}

	temp = S.top();
	head = temp;
	S.pop();
	while(!S.empty()) {
		cout << ". ";
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}

int main() {
	int count, data;
	Node *temp = NULL, *new_node = NULL;
	cout << "Reverse a linked list using stack" << "\n";
	cout << "\nNumber of elements to add in linked-list: ";
	cin >> count;
	cout << "\nEnter " << count << " numbers to add in Linked-list: ";
	for(int i = 0; i < count; i++) {
		cin >> data;
		new_node = getNewNode(data);
		if (head == NULL) {
			head = new_node;
		} else {
			temp = head;
			while(temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}

	print();

	reverseLinkedList();

	print();

	return 0;
}
