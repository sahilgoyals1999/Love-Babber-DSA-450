// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

// T.C => O(n*log(k), S.C => O(k)

vector<int> kLargest(int a[], int n, int k) {
	vector<int> ans(k);
	// Min Heap
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i) {
		if (pq.size() < k) {
			pq.push(a[i]);
		}
		else if (pq.top() < a[i]) {
			pq.pop();
			pq.push(a[i]);
		}
	}
	while (!pq.empty()) {
		ans[k - 1] = pq.top();
		pq.pop();
		--k;
	}
	return ans;
}