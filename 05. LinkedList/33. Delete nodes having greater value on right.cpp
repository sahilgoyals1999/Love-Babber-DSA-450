// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

// T.C => O(n), S.C => O(1)

Node *compute(Node *head) {
	if (!head || !head->next) return head;
	Node *temp = compute(head->next);
	if (temp->data > head->data) return temp;
	else head->next = temp;
	return head;
}