// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

// T.C => O(n), S.C => O(n)

int getPairsCount(int a[], int n, int k) {
	unordered_map<int, int> mp;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (mp.count(k - a[i]) == 1) {
			ans += mp[k - a[i]];
		}
		mp[a[i]]++;
	}
	return ans;
}