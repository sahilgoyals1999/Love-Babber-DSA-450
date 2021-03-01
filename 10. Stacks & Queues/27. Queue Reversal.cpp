// https://practice.geeksforgeeks.org/problems/queue-reversal/1#

// T.C => O(n), S.C => O(1)

void solve(queue<int> &q) {
	if (q.size() < 2) return;
	int x = q.front();
	q.pop();
	solve(q);
	q.push(x);
}

queue<int> rev(queue<int> q) {
	solve(q);
	return q;
}