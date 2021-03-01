// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#

// T.C => O(n + k), S.C => O(k)

queue<int> modifyQueue(queue<int> q, int k) {
	int n = q.size();
	n -= k;
	stack<int> st;
	while (k > 0) {
		st.push(q.front());
		q.pop();
		--k;
	}
	while (!st.empty()) {
		q.push(st.top());
		st.pop();
	}
	while (n > 0) {
		q.push(q.front());
		q.pop();
		--n;
	}
	return q;
}