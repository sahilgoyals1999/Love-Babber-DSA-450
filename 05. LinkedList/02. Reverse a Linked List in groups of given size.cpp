// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

// T.C => O(n), S.C => O(1)

struct node *reverse(struct node *head, int k) {
	// base case
	if (!head) return NULL;
	node *cur = head, *next = NULL, *prev = NULL;
	int count = 0;
	// reverse first k nodes of the linked list
	while (cur && count < k) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		count++;
	}
	/* next is now a pointer to (k+1)th node
	Recursively call for the list starting from current.
	And make rest of the list as next of first node */
	if (next) head->next = reverse(next, k);
	// prev is new head of the input list
	return prev;
}