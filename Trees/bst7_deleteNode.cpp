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

BstNode* findMinNode(BstNode *root) {
	int data = 0;
	if (root == NULL) return root;
	
	while(root->left != NULL) {
		root = root->left;
	}

	return root;
}

BstNode* deleteNode(BstNode *root, int data) {
	BstNode *temp = NULL;
	if (root == NULL) return root;
	if (root->data > data) {
		root->left = deleteNode(root->left, data);
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
	} else {
		// data found
		if (root->left != NULL && root->right != NULL) {
			// find min in right subtree or max in left subtree
			temp = findMinNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		} else if (root->left != NULL && root->right == NULL) {
			temp = root;
			root = root->left;
			delete temp;
		} else if (root->left == NULL && root->right != NULL) {
			temp = root;
			root = root->left;
			delete temp;
		} else {
			delete root;
			root = NULL;
		}
	}
	return root;			
}

void postorder(BstNode *root) {
	if (root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
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
	cout << "Post Order traversal: ";
	postorder(root);
	cout << endl;
	BstNode *temp = deleteNode(root, 25);
	cout << endl;
	cout << "Post Order traversal: ";
	postorder(root);
	cout << endl;
	return 0;
}

/*
 * OUTPUT
 * ------------
 *  Root address:0x563e3c264e70 data:15
 *  Root address:0x563e3c2652a0 data:10
 *  Root address:0x563e3c2652c0 data:20
 *  Root address:0x563e3c2652e0 data:25
 *  Root address:0x563e3c265300 data:8
 *  Root address:0x563e3c265320 data:12
 *  Root address:0x563e3c265340 data:17
 *  Root address:0x563e3c265360 data:13
 *  Root address:0x563e3c265380 data:11
 *
 *  Sum of all nodes: 131
 *  Post Order traversal: 8 11 13 12 10 17 25 20 15
 *
 *  Output of sumOfChilds: 131
 *  Post Order traversal: 8 11 13 36 54 17 25 62 131
 */
