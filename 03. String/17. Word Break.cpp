// https://practice.geeksforgeeks.org/problems/word-break1352/1#

// T.C => O(n*n), S.C => O(n)

int wordBreak(string A, vector<string> &B) {
	int n = A.length();
	unordered_map<string, int> mp;
	for (string &s : B) {
		mp[s] = 1;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		// Checking for prefix
		for (int j = i - 1; j >= 0; --j) {
			if (dp[j] == 1 && mp.count(A.substr(j, i - j)) == 1) {
				dp[i] = 1;
				break;
			}
		}
	}
	return dp[n];
}