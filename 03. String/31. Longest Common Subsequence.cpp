// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

// T.C => O(n*m), S.C => O(m)
// dp[i][j] => max length of LCS for s[0..n-1] and t[0..m-1]

int lcs(int n, int m, string s, string t) {
	int dp[2][m + 1];
	// for current and previous row
	int b;
	for (int i = 0; i <= n; ++i) {
		b = i & 1;
		for (int j = 0; j <= m; ++j) {
			if (i == 0 || j == 0) dp[b][j] = 0;
			else if (s[i - 1] == t[j - 1]) dp[b][j] = dp[1 - b][j - 1] + 1;
			else dp[b][j] = max(dp[1 - b][j], dp[b][j - 1]);
		}
	}
	// here b refer to last row so dp[n][m] ==> dp[b][m]
	return dp[b][m];
}