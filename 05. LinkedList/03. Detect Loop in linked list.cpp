// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

// T.C => O(n), S.C => O(1)

bool detectLoop(Node* head) {
	if (!head || !head->next) return false;
	Node *slow = head, *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) return true;
	}
	return false;
}