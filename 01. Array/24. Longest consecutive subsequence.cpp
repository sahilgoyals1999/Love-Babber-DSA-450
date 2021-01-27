// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// return the length of the longest subsequene of consecutive integers
// T.C => O(n), S.C => O(n)

int findLongestConseqSubseq(int a[], int n) {
	int ans = 0, s = 0;
	int mp[100001] = {};
	for (int i = 0; i < n; ++i) {
		mp[a[i]] = 1;
	}
	for (int i = 0; i < 100001; ++i) {
		if (mp[i] == 1) ++s;
		ans = max(ans, s);
		if (mp[i] == 0) s = 0;
	}
	return ans;
}