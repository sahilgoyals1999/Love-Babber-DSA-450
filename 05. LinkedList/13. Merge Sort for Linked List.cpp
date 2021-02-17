// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

// T.C => O(n*log(n)), S.C => O(1)

Node* merge(Node* l1, Node* l2) {
	Node *temp = new Node(0), *ans = temp;
	while (l1 && l2) {
		if (l1->data < l2->data) {
			temp->next = l1;
			l1 = l1->next;
		}
		else {
			temp->next = l2;
			l2 = l2->next;
		}
		temp = temp->next;
	}
	if (l1) temp->next = l1;
	else temp->next = l2;
	return ans->next;
}

Node* mergeSort(Node* head) {
	if (!head || !head->next) return head;
	Node *slow = head, *fast = head->next;
	// Finding mid
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// Divide the list into two parts (one start with head and other with fast)
	fast = slow->next;
	slow->next = NULL;
	// Merge two list after Sorting
	return merge(mergeSort(head), mergeSort(fast));
}