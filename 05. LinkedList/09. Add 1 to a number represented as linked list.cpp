// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

// T.C => O(n), S.C => O(1)

int solve(Node *head) {
	// If linked list is empty, then return carry
	if (!head) return 1;
	// Add carry returned be next node call
	int s = head->data + solve(head->next);
	// Update data and return new carry
	head->data = s % 10;
	return s / 10;
}

Node* addOne(Node *head) {
	// Add 1 to linked list from end to beginning
	int c = solve(head);
	// If there is carry after processing all nodes,
	// then we need to add a new node to linked list
	if (c) {
		Node* newNode = new Node(c);
		newNode->next = head;
		return newNode; // New node becomes head now
	}
	return head;
}