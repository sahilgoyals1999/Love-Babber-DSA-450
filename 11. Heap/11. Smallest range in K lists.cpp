// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1#

// T.C => O(n*k*log(k)), S.C => O(k)

pair<int, int> findSmallestRange(int a[][N], int n, int k) {
	pair<int, int> ans;
	int res = INT_MAX, mx = INT_MIN, mn = INT_MAX;
	priority_queue<pair<int, pair<int, int>>,
	               vector<pair<int, pair<int, int>>>,
	               greater<pair<int, pair<int, int>>>> pq;
	// Insert first element of each row
	for (int i = 0; i < k; ++i) {
		pq.push({a[i][0], {i, 0}});
		mx = max(mx, a[i][0]);
	}
	while (1) {
		pair<int, pair<int, int>> tp = pq.top();
		pq.pop();
		mn = tp.first;
		int r = tp.second.first;
		int c = tp.second.second;
		// update ans
		if (abs(mx - mn) < res) {
			res = mx - mn;
			ans.first = mn;
			ans.second = mx;
		}
		// if any row is completed break the loop
		if (c == n - 1) break;
		mx = max(mx, a[r][c + 1]);
		pq.push({a[r][c + 1], {r, c + 1}});
	}
	return ans;
}