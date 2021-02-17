// https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/

// T.C => O(n), S.C => O(1)

void pairSum(Node *head, int target) {
	// Set two pointers, left to the beginning of DLL and right to the end of DLL.
	Node *left = head, *right = head;
	while (right->next) {
		right = right->next;
	}
	// The loop terminates when either of two pointers become NULL,
	// or they cross each other (second->next == first),
	// or they become same (first == second)
	while (left && right && left != right && right->next != left) {
		// pair found
		int sum = left->data + right->data;
		if (sum == target) {
			cout << left->data << " " << right->data << "\n";
			// move left in forward direction
			left = left->next;
			// move right in backward direction
			right = right->prev;
		}
		else if (sum < target) left = left->next;
		else right = right->prev;
	}
}