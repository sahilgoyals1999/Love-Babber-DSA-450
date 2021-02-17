// https://practice.geeksforgeeks.org/problems/circular-linked-list/1

// T.C => O(n), S.C => O(1)

bool isCircular(Node *head) {
	if (!head || !head->next) return false;
	Node *temp = head->next;
	while (temp) {
		if (temp == head) return true;
		temp = temp->next;
	}
	return false;
}