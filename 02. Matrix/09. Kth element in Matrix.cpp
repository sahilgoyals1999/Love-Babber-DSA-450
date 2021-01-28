// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#

// T.C => O(n*log(n), S.C => O(k)

int kthSmallest(int a[MAX][MAX], int n, int k) {
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (pq.size() < k) {
				pq.push(a[i][j]);
			}
			else if (pq.top() > a[i][j]) {
				pq.pop();
				pq.push(a[i][j]);
			}
			else break;
		}
	}
	return pq.top();
}