// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#

// T.C => O(n), S.C => O(1)

Node* reverse(Node* slow) {
	Node *cur = slow, *prev = NULL;
	while (cur) {
		Node *next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

bool isPalindrome(Node *head) {
	Node *slow = head, *fast = head;
	// split in two half
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = head;
	// reverse the second half
	slow = reverse(slow);
	while (slow) {
		if (fast->data != slow->data) return false;
		slow = slow->next;
		fast = fast->next;
	}
	return true;
}