// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

// T.C => O(n+m), S.C => O(1)

int rowWithMax1s(vector<vector<int>> a, int n, int m) {
	int ans = -1, j = m - 1;
	for (int i = 0; i < n; ++i) {
		while (j >= 0 && a[i][j] == 1) {
			ans = i;
			--j;
		}
	}
	return ans;
}