// https://leetcode.com/problems/middle-of-the-linked-list/

// T.C => O(n/2) , S.C => O(1)

ListNode* middleNode(ListNode* head) {
	ListNode *slow = head, *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}