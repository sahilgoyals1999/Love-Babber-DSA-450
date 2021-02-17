// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

// T.C => O(2*(n+m)), S.C => O(1)

int intersectPoint(Node* head1, Node* head2) {
	int l1 = 0, l2 = 0;
	Node *temp1 = head1, *temp2 = head2;
	// find length of first LL
	while (temp1) {
		++l1;
		temp1 = temp1->next;
	}
	// find length of second LL
	while (temp2) {
		++l2;
		temp2 = temp2->next;
	}
	// move head1 till same length
	while (l1 > l2) {
		head1 = head1->next;
		--l1;
	}
	// move head2 till same length
	while (l1 < l2) {
		head2 = head2->next;
		--l2;
	}
	while (head1 != head2) {
		head1 = head1->next;
		head2 = head2->next;
	}
	// if we dont find a common element
	if (!head1) return -1;
	return head1->data;
}