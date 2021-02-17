// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

// T.C => O(n), S.C => O(1)

Node* divide(int N, Node *head) {
	Node *odd = new Node(-1), *oddHead = odd;
	Node *even = new Node(-1), *evenHead = even;
	Node *temp = head;
	while (temp) {
		if (temp->data % 2 == 0) {
			even->next = temp;
			even = even->next;
		}
		else {
			odd->next = temp;
			odd = odd->next;
		}
		temp = temp->next;
	}
	even->next = oddHead->next;
	odd->next = NULL;
	return evenHead->next;
}