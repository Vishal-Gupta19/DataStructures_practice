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

// Preorder Traversal: root, left, right
void preorder(BstNode *root) {
	if (root == NULL) {
		return;
	}

	cout << (char)root->data << " ";

	preorder(root->left);

	preorder(root->right);
}

// Inorder Traversal: left, root, right
void inorder(BstNode *root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);

	cout << (char)root->data << " ";

	inorder(root->right);
}

// Postorder Traversal: left, right, root
void postorder(BstNode *root) {
	if (root == NULL) {
		return;
	}

	postorder(root->left);

	postorder(root->right);

	cout << (char)root->data << " ";
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
	cout << endl << "Traversing the tree in preorder way: ";
	preorder(root);
	cout << endl << "Traversing the tree in inorder way: ";
	inorder(root);
	cout << endl << "Traversing the tree in postorder way: ";
	postorder(root);
	cout << endl;
	return 0;
}

/*
 * OUTPUT
 * ------------
 *  Root address:0x562876892e70 data: F
 *  Root address:0x5628768932a0 data: D
 *  Root address:0x5628768932c0 data: B
 *  Root address:0x5628768932e0 data: A
 *  Root address:0x562876893300 data: C
 *  Root address:0x562876893320 data: E
 *  Root address:0x562876893340 data: J
 *  Root address:0x562876893360 data: G
 *  Root address:0x562876893380 data: I
 *  Root address:0x5628768933a0 data: H
 *  Root address:0x5628768933c0 data: K
 *
 *
 *  Traversing the tree in preorder way: F D B A C E J G I H K
 *  Traversing the tree in inorder way: A B C D E F G H I J K
 *  Traversing the tree in postorder way: A C B E D H I G K J F
 */
