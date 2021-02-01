
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

// T.C => O(n^2), S.C => O(n^2)

int LongestRepeatingSubsequence(string s) {
	int n = s.length();
	int dp[n + 1]][n + 1] = {};
	// Fill dp table (similar to LCS loops)
	for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= n; ++j) {
			// If characters match and indexes are not same
			if (s[i - 1] == s[j - 1] && i != j) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	return dp[n][n];
}