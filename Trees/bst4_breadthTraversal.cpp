#include<iostream>
#include<queue>

using namespace std;

typedef struct BstNode {
	char data;
	BstNode* left;
	BstNode* right;
} BstNode;

BstNode* getNewNode(int data) {
	BstNode *newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode *root, int data) {
	if (root == NULL) {
		root = getNewNode(data);
		if (root != NULL) cout << "Root address:" << root << " data: "  << (char)data << endl;
	} else if (root->data >= data) {
		root->left = Insert(root->left, data);
	} else {
		root->right = Insert(root->right, data);
	}

	return root;
}

void breadthTraversal(BstNode *root) {
	if (root == NULL) return;

	queue<BstNode*> Q;

	Q.push(root);

	while(!Q.empty()) {
		BstNode *curr = Q.front();
		cout << curr->data << " ";
		if (curr->left != NULL) Q.push(curr->left);
		if (curr->right != NULL) Q.push(curr->right);
		Q.pop();
	}
}

int main() {
	BstNode *root = NULL;
	root = Insert(root, 'F');
	root = Insert(root, 'D');
	root = Insert(root, 'B');
	root = Insert(root, 'A');
	root = Insert(root, 'C');
	root = Insert(root, 'E');
	root = Insert(root, 'J');
	root = Insert(root, 'G');
	root = Insert(root, 'I');
	root = Insert(root, 'H');
	root = Insert(root, 'K');

	cout << endl;
	cout << "Traversing the tree in breath-first way: ";
	breadthTraversal(root);
	cout << endl;
	return 0;
}

/*
 * OUTPUT
 * ------------
 *  Root address:0x559e90044e70 data: F
 *  Root address:0x559e900452a0 data: D
 *  Root address:0x559e900452c0 data: B
 *  Root address:0x559e900452e0 data: A
 *  Root address:0x559e90045300 data: C
 *  Root address:0x559e90045320 data: E
 *  Root address:0x559e90045340 data: J
 *  Root address:0x559e90045360 data: G
 *  Root address:0x559e90045380 data: I
 *  Root address:0x559e900453a0 data: H
 *  Root address:0x559e900453c0 data: K
 *
 *  Traversing the tree in breath-first way: F D J B E G K A C I H
 */
