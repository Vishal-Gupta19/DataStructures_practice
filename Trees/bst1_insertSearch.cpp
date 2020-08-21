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

bool Search(BstNode* root, int data) {
	cout << "Root address:0x%x" << root << endl;
	if (root == NULL) return false;
	else if (data == root->data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

int main() {
	BstNode *root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	cout << endl;

	int num;
	cout << "Enter number to be searched: ";
	cin >> num;
	if (Search(root, num) == true) {
		cout << endl << "Number found !!!" << endl;
	} else {
		cout << endl << "Number not found !!!" << endl;
	}
	return 0;
}

/*
 * OUTPUT
 * ------------
 *  Root address:0x564bd5127e70 data:15
 *  Root address:0x564bd51282a0 data:10
 *  Root address:0x564bd51282c0 data:20
 *  Root address:0x564bd51282e0 data:25
 *  Root address:0x564bd5128300 data:8
 *  Root address:0x564bd5128320 data:12
 *
 *  Enter number to be searched: 25
 *  Root address:0x%x0x564bd5127e70
 *  Root address:0x%x0x564bd51282c0
 *  Root address:0x%x0x564bd51282e0
 *
 *  Number found !!!
 *  vishal@DESKTOP-T7BOG2T:~/Coding_practice/DataStructures_practice/Trees$ ../output/tree.out
 *  Root address:0x559ed7218e70 data:15
 *  Root address:0x559ed72192a0 data:10
 *  Root address:0x559ed72192c0 data:20
 *  Root address:0x559ed72192e0 data:25
 *  Root address:0x559ed7219300 data:8
 *  Root address:0x559ed7219320 data:12
 *
 *  Enter number to be searched: 30
 *  Root address:0x%x0x559ed7218e70
 *  Root address:0x%x0x559ed72192c0
 *  Root address:0x%x0x559ed72192e0
 *  Root address:0x%x0
 *
 *  Number not found !!!
 */
