// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#

// T.C => O(n), S.C => O(1)

Node *copyList(Node *head) {
	Node *temp = head;
	// S1: make copy of each node, and link them together side-by-side in a single list.
	while (temp) {
		Node *front = temp->next;
		Node *newNode = new Node(temp->data);
		temp->next = newNode;
		newNode->next = front;
		temp = front;
	}
	// S2: assign random pointers for the copy nodes.
	temp = head;
	while (temp) {
		if (temp->arb) temp->next->arb = temp->arb->next;
		temp = temp->next->next;
	}
	// S3: restore the original list, and extract the copy list.
	temp = head;
	Node *newHead = new Node(0);
	Node *copy = newHead;
	while (temp) {
		Node *front = temp->next->next;
		// extract the copy
		copy->next = temp->next;
		// restore the original list
		temp->next = front;
		copy = copy -> next;
		temp = front;
	}
	return newHead->next;
}