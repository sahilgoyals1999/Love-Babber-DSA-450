// https://practice.geeksforgeeks.org/problems/valid-substring0624/1

// T.C => O(n), S.C => O(1)

int findMaxLen(string s) {
	int n = s.length();
	// Variables for left and right counter.
	// maxlength to store the maximum length found so far
	int left = 0, right = 0, ans = 0;
	// Iterating the string from left to right
	for (int i = 0; i < n; ++i) {
		// If "(" is encountered => left counter is incremented
		// else => right counter is incremented
		if (s[i] == '(') ++left;
		else ++right;
		// Whenever left is equal to right, it signifies that the subsequence is valid and
		if (left == right) ans = max(ans, left + right);
		// Reseting the counters when the subsequence becomes invalid
		else if (right > left) {
			left = 0;
			right = 0;
		}
	}
	left = 0;
	right = 0;
	// Iterating the string from right to left
	for (int i = n - 1; i >= 0; --i) {
		// If "(" is encountered => left counter is incremented
		// else => right counter is incremented
		if (s[i] == '(') ++left;
		else ++right;
		// Whenever left is equal to right, it signifies that the subsequence is valid and
		if (left == right) ans = max(ans, left + right);
		// Reseting the counters when the subsequence becomes invalid
		else if (left > right) {
			left = 0;
			right = 0;
		}
	}
	return ans;
}