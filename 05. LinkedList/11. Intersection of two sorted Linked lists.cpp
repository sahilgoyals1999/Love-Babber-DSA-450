// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

// T.C => O(n+m), S.C => O(1)

Node* findIntersection(Node* head1, Node* head2) {
	Node *temp = new Node(0), *ans = temp;
	while (head1 && head2) {
		if (head1->data < head2->data) {
			head1 = head1->next;
		}
		else if (head1->data > head2->data) {
			head2 = head2->next;
		}
		else {
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	temp->next = NULL;
	return ans->next;
}