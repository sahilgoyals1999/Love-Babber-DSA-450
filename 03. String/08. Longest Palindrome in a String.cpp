// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

// T.C => O(n^2), S.C => O(1)

void longestPalSubstr(string s) {
	int mx = 1;
	int start = 0;
	int l = s.length();
	for (int i = 1; i < l; ++i) {
		// Find the longest even length palindrome with center points as i-1 and i.
		int low = i - 1;
		int high = i;
		while (low >= 0 && high < l && s[low] == s[high]) {
			if (high - low + 1 > mx) {
				start = low;
				mx = high - low + 1;
			}
			--low;
			++high;
		}
		// Find the longest odd length palindrome with center point as i
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < l && s[low] == s[high]) {
			if (high - low + 1 > mx) {
				start = low;
				mx = high - low + 1;
			}
			--low;
			++high;
		}
	}
	for (int i = start; i < start + mx; ++i) {
		cout << s[i];
	}
}