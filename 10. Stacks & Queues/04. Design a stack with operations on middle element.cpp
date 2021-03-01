// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

// T.C => O(1), S.C => O(1) for all operations

#include <bits/stdc++.h>
using namespace std;

// A Doubly Linked List Node
class DLLNode {
public:
	DLLNode *prev;
	int data;
	DLLNode *next;
};

/* Representation of the stack data structure that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node, pointer to middle node and count of nodes */
class myStack {
public:
	DLLNode *head;
	DLLNode *mid;
	int count;
};

// Function to create the stack data structure
myStack *createMyStack() {
	myStack *ms = new myStack();
	ms->count = 0;
	return ms;
};

// Function to push an element to the stack
void push(myStack *ms, int data) {
	// allocate DLLNode and put in data
	DLLNode* node = new DLLNode();
	node->data = data;
	// Since we are adding at the beginning, prev is always NULL
	node->prev = NULL;
	// link the old list off the new DLLNode
	node->next = ms->head;
	// Increment count of items in stack
	ms->count++;
	/* Change mid pointer in two cases
	1) Linked List is empty
	2) Number of nodes in linked list is even */
	if (ms->count == 1) {
		ms->mid = node;
	}
	else {
		ms->head->prev = node;
		// Update mid if ms->count is even
		if (!(ms->count & 1)) {
			ms->mid = ms->mid->prev;
		}
	}
	// move head to point to the new DLLNode
	ms->head = node;
}

// Function to pop an element from stack
int pop(myStack *ms) {
	// Stack underflow
	if (ms->count == 0) return -1;
	DLLNode *head = ms->head;
	int item = head->data;
	ms->head = head->next;
	// If linked list doesn't become empty, update prev of new head as NULL
	if (ms->head != NULL) {
		ms->head->prev = NULL;
	}
	ms->count--;
	// update the mid pointer when we have odd number of elements in the stack
	// i,e move down the mid pointer.
	if ((ms->count) & 1) {
		ms->mid = ms->mid->next;
	}
	free(head);
	return item;
}

// Function for finding middle of the stack
int findMiddle(myStack *ms) {
	if (ms->count == 0) return -1;
	return ms->mid->data;
}

int deleteMiddle(myStack *ms) {
	if (ms->count == 0) return -1;
	DLLNode *mid = ms->mid;
	int item = mid->data;
	ms->count--;
	if (ms->count == 1) {
		ms->head = ms->head->next;
		ms->mid = ms->head;
	}
	else if (ms->count > 0) {
		ms->mid->prev->next = ms->mid->next;
		ms->mid->next->prev = ms->mid->prev;
		// odd elements
		if ((ms->count) & 1) {
			ms->mid = ms->mid->next;
		}
		else {
			ms->mid = ms->mid->prev;
		}
		free(mid);
		return item;
	}
}

// Driver code
int main() {
	myStack *ms = createMyStack();
	push(ms, 11);
	push(ms, 22);
	push(ms, 33);
	push(ms, 44);
	push(ms, 55);
	push(ms, 66);
	push(ms, 77);
	cout << "Item popped is " << pop(ms) << endl;
	cout << "Item popped is " << pop(ms) << endl;
	cout << "Middle Element is " << findMiddle(ms) << endl;
	return 0;
}