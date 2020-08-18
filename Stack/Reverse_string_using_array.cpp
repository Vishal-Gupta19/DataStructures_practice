#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

/*
class Stack
{
	private:
		char A[101];
		int top;
	public:
		void Push(int x);
		void Pop();
		int Top();
		bool IsEmpty();
};

Time Complexity = O(n)
Space Complexity = O(n)
*/

void reverseUsingStack(char *arr, int len) {
	cout << "Reversing the string using stack. . ." << "\n";
	stack<char> S;
	// loop for push
	for(int i = 0; i < len; i++) {
		S.push(arr[i]);
	}

	// loop for pop
	for(int i = 0; i < len; i++) {
		arr[i] = S.top();
		S.pop();
	}
}

int main() {
	char arr[50];
	cout << "\nEnter a string:";
	cin >> arr;
	reverseUsingStack(arr, strlen(arr));
	cout << arr << "\n";

	return 0;
}
