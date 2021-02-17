// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

// T.C => O(n), S.C => O(1)

/*
m => distance of first node of cycle from head
n => length of cycle
k => distance of point where slow and fast meet

=> distance traveled by fast pointer = 2 * distance traveled by slow pointer
=> (m + n*x + k) = 2*(m + n*y + k)
=> m + k = (x - 2*y)*n

x => number of complete cyclic rounds made by fast pointer before they meet first time
y => number of complete cyclic rounds made by slow pointer before they meet first time

Now, (m+k) is a multiple of n
thus we can write, m + k = i*n or m = i*n - k
Hence, distance moved by slow pointer: m, is equal to distance moved by fast pointer:
i*n - k or (i-1)*n + n - k (cover the loop completely i-1 times and start from n-k).

So if we start moving both pointers again at same speed
such that one pointer (say slow) begins from head node of linked list and
other pointer (say fast) begins from meeting point.
When slow pointer reaches beginning of loop (has made m steps),
fast pointer would have made also moved m steps as they are now moving same pace.
Since m+k is a multiple of n and fast starts from k,
they would meet at the beginning.
Can they meet before also? No because slow pointer enters the cycle first time after m steps.
*/

void removeLoop(Node* head) {
	if (!head || !head->next) return;
	Node *slow = head, *fast = head, *entry = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}
	// If loop exists
	if (slow == fast) {
		slow = head;
		// this check is needed when slow and fast both meet at the head of the LL
		if (slow == fast) {
			while (fast->next != slow) {
				fast = fast->next;
			}
		}
		else {
			while (slow->next != fast->next) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		// since fast->next is the looping point
		fast->next = NULL;
	}
}