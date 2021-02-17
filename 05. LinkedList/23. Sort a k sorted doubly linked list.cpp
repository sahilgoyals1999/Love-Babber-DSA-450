// https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/

// T.C => O(n*log(k)), S.C => O(k)

bool comp(Node* p1, Node* p2) {
	return p1->data > p2->data;
}

// function to sort a k sorted DLL
Node* sortAKSortedDLL(Node* head, int k) {
	// if list is empty
	if (!head) return head;
	// MIN HEAP with the help of 'comp' function
	priority_queue<Node*, vector<Node*>, comp> pq;
	// 'last' points to the last node of the result sorted list so far
	Node* newHead = NULL, *last;
	// Create a Min Heap of first (k+1) elements from input DLL
	for (int i = 0; head != NULL && i <= k; ++i) {
		// push the node on to 'pq'
		pq.push(head);
		// move to the next node
		head = head->next;
	}
	// loop till there are elements in 'pq'
	while (!pq.empty()) {
		// place top of 'pq' at the end of the
		// result sorted list so far having the first node
		// pointed to by 'newHead'
		// and adjust the required links
		if (!newHead) {
			newHead = pq.top();
			newHead->prev = NULL;
			last = newHead;
		}
		else {
			last->next = pq.top();
			pq.top()->prev = last;
			last = pq.top();
		}
		// remove element from 'pq'
		pq.pop();
		// if there are more nodes left in the input list
		if (head) {
			// push the node on to 'pq'
			pq.push(head);
			// move to the next node
			head = head->next;
		}
	}
	last->next = NULL;
	return newHead;
}