// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

// T.C => O(n), S.C => O(1)
// Traverse the LL and swap the prev and the next pointer

Node* reverseDLL(Node *head) {
	if (!head || !head->next) return head;
	Node *prev = NULL, *cur = head;
	while (cur) {
		prev = cur->prev;
		cur->prev = cur->next;
		cur->next = prev;
		cur = cur->prev;
	}
	return prev->prev;
}