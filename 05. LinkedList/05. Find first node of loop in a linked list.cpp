// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

// T.C => O(n), S.C => O(1)

// Function to detect and remove loop in a linked list that may contain loop
Node* detectAndRemoveLoop(Node* head) {
	// If list is empty or has only one node without loop
	if (!head || !head->next) return NULL;
	Node *slow = head, *fast = head;
	// Move slow and fast 1 and 2 steps ahead respectively.
	slow = slow->next;
	fast = fast->next->next;
	// Search for loop using slow and fast pointers
	while (fast && fast->next) {
		if (slow == fast) break;
		slow = slow->next;
		fast = fast->next->next;
	}
	// If loop does not exist
	if (slow != fast) return NULL;
	// If loop exists. Start slow from head and fast from meeting point.
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}