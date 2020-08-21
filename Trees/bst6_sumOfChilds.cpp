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

int sumOfNodes(BstNode *root) {
	 if (root == NULL) return 0;
	 else {return (root->data + sumOfNodes(root->left) + sumOfNodes(root->right));}
}

int sumOfChilds(BstNode *root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data;

	int left_val = 0, right_val = 0;
	if (root->left != NULL) {
		left_val = sumOfChilds(root->left);
	}
	if (root->right != NULL) {
		right_val = sumOfChilds(root->right);
	}
	root->data = root->data + left_val + right_val;
	return root->data;
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
	int sum_all = sumOfNodes(root);
	cout << "Sum of all nodes: " << sum_all << endl;
	cout << "Post Order traversal: ";
	postorder(root);
	cout << endl;
	cout << endl;
	cout << "Output of sumOfChilds: " << sumOfChilds(root);
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
