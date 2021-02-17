// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#

// T.C => O(n), S.C => O(1)

int getNthFromLast(Node *head, int n) {
	Node *p = head, *f = head;
	for (int i = 1; i < n; ++i) {
		f = f->next;
		if (!f) return -1;
	}
	while (f->next) {
		p = p->next;
		f = f->next;
	}
	return p->data;
}