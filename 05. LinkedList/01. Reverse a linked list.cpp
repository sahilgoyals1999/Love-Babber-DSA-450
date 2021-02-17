// https://www.geeksforgeeks.org/reverse-a-linked-list/

// Iterative
// T.C => O(n), S.C => O(1)
struct Node* reverseList(struct Node *head) {
	struct Node *cur = head, *prev = NULL;
	while (cur) {
		// store next
		Node *next = cur->next;
		// Reverse current node's pointer
		cur->next = prev;
		// Move pointers one position ahead.
		prev = cur;
		cur = next;
	}
	return prev;
}

// Recursive
// T.C => O(n), S.C => O(1)
struct Node* reverseList(struct Node *head) {
	if (!head || !head->next) return head;
	// reverse the rest list and put the first element at the end
	Node *rest = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}