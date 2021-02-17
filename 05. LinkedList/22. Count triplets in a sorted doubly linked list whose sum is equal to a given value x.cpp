// https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/

// T.C => O(n^2), S.C => O(1)

// function to count pairs whose sum equal to given 'value'
int countPairs(Node* left, Node* right, int value) {
	int count = 0;
	// The loop terminates when either of two pointers become NULL,
	// or they cross each other (right->next == left),
	// or they become same (left == right)
	while (left && right && left != right && right->next != left) {
		// pair found
		int sum = left->data + right->data;
		if (sum == value) {
			count++;
			// move left in forward direction
			left = left->next;
			// move right in backward direction
			right = right->prev;
		}
		// if sum is greater than 'value' move right in backward direction
		else if (sum > value) right = right->prev;
		// else move left in forward direction
		else left = left->next;
	}
	return count;
}

// function to count triplets in a sorted doubly linked list whose sum is equal to a given value 'x'
int countTriplets(Node* head, int x) {
	int count = 0;
	// if list is empty
	if (!head) return count;
	Node* cur = head, *last = head;
	// get pointer to the right node of the DLL
	while (last->next) {
		last = last->next;
	}
	while (cur) {
		// count pairs with sum(x - cur->data) in the range left to right
		count += countPairs(cur->next, last, x - cur->data);
		cur = cur->next;
	}
	return count;
}