// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// T.C => O(n), S.C => O(1)

Node* segregate(Node *head) {
	Node *zero = new Node(-1), *zeroHead = zero;
	Node *one = new Node(-1), *oneHead = one;
	Node *two = new Node(-1), *twoHead = two;
	Node *temp = head;
	while (temp) {
		if (temp->data == 0) {
			zero->next = temp;
			zero = zero->next;
		}
		else if (temp->data == 1) {
			one->next = temp;
			one = one->next;
		}
		else {
			two->next = temp;
			two = two->next;
		}
		temp = temp->next;
	}
	if (oneHead->next) {
		zero->next = oneHead->next;
	}
	else {
		zero->next = twoHead->next;
	}
	one->next = twoHead->next;
	two->next = NULL;
	return zeroHead->next;
}