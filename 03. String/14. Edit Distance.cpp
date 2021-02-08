// https://practice.geeksforgeeks.org/problems/edit-distance3702/1

// T.C => O(n*m), S.C => O(n*m)

int editDistance(string s, string t) {
	int n = s.length();
	int m = t.length();
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			// If first string is empty, only option is to insert all characters of second string
			if (i == 0) dp[i][j] = j; // Min. operations = j
			// If second string is empty, only option is to remove all characters of second string
			else if (j == 0) dp[i][j] = i; // Min. operations = i
			// If last characters are same, ignore last char and recur for remaining string
			else if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			// If the last character is different, consider all possibilities and find the minimum
			else {
				dp[i][j] = 1 + min({dp[i][j - 1],      // Insert
				                    dp[i - 1][j],      // Remove
				                    dp[i - 1][j - 1]   // Replace
				                   });
			}
		}
	}
	return dp[n][m];
}