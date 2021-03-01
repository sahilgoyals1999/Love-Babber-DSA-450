// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#

// T.C => O(1), S.C => O(1)

void QueueStack :: push(int x) {
	q1.push(x);
}

// T.C => O(n), S.C => O(1)

int QueueStack :: pop() {
	if (q1.empty()) return -1;
	while (q1.size() > 1) {
		q2.push(q1.front());
		q1.pop();
	}
	int x = q1.front();
	// assign q2 to q1 and a empty queue to q2
	queue<int> q;
	q1 = q2;
	q2 = q;
	return x;
}