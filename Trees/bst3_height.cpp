#include<iostream>
#include<cstring>

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

int funcCallCount = 0;

int findHeight(BstNode *root) {
	funcCallCount++;
	int leftHeight = 0, rightHeight = 0;
	if (root == NULL) {
		return -1;
	} else {
		leftHeight = findHeight(root->left);
		rightHeight = findHeight(root->right);
	}

	if (root != NULL) cout << "data:" << root->data << endl;
	cout << "left:"<< leftHeight << endl;
	cout << "right:"<< rightHeight << endl;
	cout << "----------------------" << endl;
	if (leftHeight >= rightHeight) return leftHeight+1;
	else return rightHeight+1;
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
	root = Insert(root, 13);
	root = Insert(root, 11);

	cout << endl;
	int height = findHeight(root);
	cout << "Height of the BST is: " << height << endl;
	cout << "Function has been called " << funcCallCount << " times." << endl;
	return 0;
}

/*
 * OUTPUT
 * ------------
 *  Root address:0x559c77650e70 data:15
 *  Root address:0x559c776512a0 data:10
 *  Root address:0x559c776512c0 data:20
 *  Root address:0x559c776512e0 data:25
 *  Root address:0x559c77651300 data:8
 *  Root address:0x559c77651320 data:12
 *  Root address:0x559c77651340 data:17
 *  Root address:0x559c77651360 data:13
 *  Root address:0x559c77651380 data:11
 *
 *  data:8
 *  left:-1
 *  right:-1
 *  ----------------------
 *  data:11
 *  left:-1
 *  right:-1
 *  ----------------------
 *  data:13
 *  left:-1
 *  right:-1
 *  ----------------------
 *  data:12
 *  left:0
 *  right:0
 *  ----------------------
 *  data:10
 *  left:0
 *  right:1
 *  ----------------------
 *  data:17
 *  left:-1
 *  right:-1
 *  ----------------------
 *  data:25
 *  left:-1
 *  right:-1
 *  ----------------------
 *  data:20
 *  left:0
 *  right:0
 *  ----------------------
 *  data:15
 *  left:2
 *  right:1
 *  ----------------------
 *  Height of the BST is: 3
 *  Function has been called 19 times.
 */
