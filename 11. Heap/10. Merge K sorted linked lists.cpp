// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

// T.C => O(n*k*log(k)), S.C => O(k)

struct comp {
	bool operator()(const Node* l, const Node* r) {
		return l->data > r->data;
	}
};

Node* mergeKLists(Node *a[], int n) {
	Node *temp = new Node(0), *head = temp;
	priority_queue<Node*, vector<Node*> , comp> pq;
	for (int i = 0; i < n; ++i) {
		if (a[i]) pq.push(a[i]);
	}
	while (!pq.empty()) {
		Node *tp = pq.top();
		pq.pop();
		if (tp->next) pq.push(tp->next);
		temp->next = tp;
		temp = temp->next;
	}
	return head->next;
}