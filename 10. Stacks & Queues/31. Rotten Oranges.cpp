// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

// T.C => O(n*m), S.C => O(n*m)

int orangesRotting(vector<vector<int>>& a) {
	int fr = 0, ans = 0;
	int n = a.size();
	int m = a[0].size();
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 2) {
				q.push({i, j});
			}
			else if (a[i][j] == 1) {
				fr++;
			}
		}
	}
	while (!q.empty()) {
		int sz = q.size(), c = 0;
		while (sz > 0) {
			pair<int, int> cur = q.front();
			q.pop();
			int i = cur.first;
			int j = cur.second;
			if (i + 1 < n && a[i + 1][j] == 1) {
				a[i + 1][j] = 2;
				q.push({i + 1, j});
				fr--;
				c = 1;
			}
			if (i - 1 >= 0 && a[i - 1][j] == 1) {
				a[i - 1][j] = 2;
				q.push(make_pair(i - 1, j));
				fr--;
				c = 1;
			}
			if (j + 1 < m && a[i][j + 1] == 1) {
				a[i][j + 1] = 2;
				q.push({i, j + 1});
				fr--;
				c = 1;
			}
			if (j - 1 >= 0 && a[i][j - 1] == 1) {
				a[i][j - 1] = 2;
				q.push({i, j - 1});
				fr--;
				c = 1;
			}
			--sz;
		}
		if (c == 1) ans++;
	}
	return (fr == 0) ? ans : -1;
}