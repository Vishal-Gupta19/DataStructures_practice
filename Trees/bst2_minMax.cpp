#include<iostream>
#include<cstring>
//#include<malloc>

using namespace std;

typedef struct BstNode {
	int data;
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
		if (root != NULL) cout << "Root address:" << root << " data:"  << data << endl;
	} else if (root->data >= data) {
		root->left = Insert(root->left, data);
	} else {
		root->right = Insert(root->right, data);
	}

	return root;
}

// Iterative approach to find minimum in a BST
int findMinIterative(BstNode *root) {
	if (root == NULL) {
		cout << "Root is NULL" << endl;
		return -1;
	} 

	while(root->left != NULL) {
		root = root->left;
	}
	
	return root->data;
}

// Iterative approach to find maximum in BST
int findMaxIterative(BstNode *root) {
	if (root == NULL) {
		cout << "Root is NULL" << endl;
		return -1;
	}

	while(root->right != NULL) {
		root = root->right;
	}

	return root->data;
}

// Recursive approach
int findMinRecursive(BstNode *root) {
	if (root == NULL) {
		cout << "Root is NULL" << endl;
		return -1;
	} else if (root->left == NULL) {
		return root->data;
	}

	return findMinRecursive(root->left);
}

// Recursive approach
int findMaxRecursive(BstNode *root) {
	if (root == NULL) {
		cout << "Root is NULL" << endl;
		return -1;
	} else if (root->right == NULL) {
		return root->data;
	}

	return findMaxRecursive(root->right);
}

int main() {
	BstNode *root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	root = Insert(root, 17);

	cout << endl;

	int num;
	cout << "Min value using Iterative approach is: " << findMinIterative(root) << endl;
	cout << "Max value using Iterative approach is: " << findMaxIterative(root) << endl;
	cout << endl;
	cout << "Min value using Recursive approach is: " << findMinRecursive(root) << endl;
	cout << "Max value using Recursive approach is: " << findMaxRecursive(root) << endl;
	return 0;
}

/*
 * OUTPUT
 * ------------
 *  Root address:0x561fb35f8e70 data:15
 *  Root address:0x561fb35f92a0 data:10
 *  Root address:0x561fb35f92c0 data:20
 *  Root address:0x561fb35f92e0 data:25
 *  Root address:0x561fb35f9300 data:8
 *  Root address:0x561fb35f9320 data:12
 *  Root address:0x561fb35f9340 data:17
 *
 *  Min value using Iterative approach is: 8
 *  Max value using Iterative approach is: 25
 *
 *  Min value using Recursive approach is: 8
 *  Max value using Recursive approach is: 25
 */
