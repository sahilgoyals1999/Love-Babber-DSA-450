// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#

// T.C => O(n*m), S.C => O(n*m)

vector<vector<int>>nearest(vector<vector<int>> a) {
	int n = a.size();
	int m = a[0].size();
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// store where 1 is present;
			if (a[i][j] == 1) {
				q.push({i, j});
			}
			a[i][j] = INT_MAX;
		}
	}
	int row_val[] = { -1, 1, 0, 0};
	int col_val[] = {0, 0, -1, 1};
	int dis = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz > 0) {
			pair<int, int> p = q.front();
			q.pop();
			int x = p.first;
			int y = p.second;
			a[x][y] = min(dis, a[x][y]);
			for (int k = 0; k < 4; ++k) {
				int r = x + row_val[k];
				int c = y + col_val[k];
				if (r >= 0 && r < n && c >= 0 && c < m && a[r][c] == INT_MAX) {
					q.push({r, c});
				}
			}
			--sz;
		}
		dis++;
	}
	return a;
}