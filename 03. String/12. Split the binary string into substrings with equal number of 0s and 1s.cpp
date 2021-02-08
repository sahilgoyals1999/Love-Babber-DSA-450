// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

// T.C => O(n), S.C => O(1)

// return the count of maximum substrings s can be divided into
int maxSubStr(string s, int n) {
	// To store the count of 0s and 1s
	int count[2] = {};
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		count[s[i] - '0']++;
		if (count[0] == count[1]) ++ans;
	}
	return (count[0] != count[1]) ? -1 : ans;
}