// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

// T.C => O(n*k*log(k)), S.C => O(k)

// pair<int, pair<int,int>> p
// p.first => element value
// p.second.first => row number
// p.second.second => col number

int *mergeKArrays(int a[][N], int k) {
	// Min-Heap
	priority_queue<pair<int, pair<int, int>>,
	               vector<pair<int, pair<int, int>>>,
	               greater<pair<int, pair<int, int>>>> pq;
	// first first element of each row
	for (int i = 0; i < k; ++i) {
		pq.push({a[i][0], {i, 0}});
	}
	int *ans = new int[k * k];
	int i = 0;
	while (!pq.empty()) {
		pair<int, pair<int, int>> tp = pq.top();
		pq.pop();
		ans[i] = tp.first;
		++i;
		int r = tp.second.first;
		int c = tp.second.second;
		// if it is a last element of the row then continue
		if (c == k - 1) continue;
		pq.push({a[r][c + 1], {r, c + 1}});
	}
	return ans;
}