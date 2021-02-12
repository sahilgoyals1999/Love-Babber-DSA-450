// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

// T.C => O(n), S.C => O(n)

ll findSubarray(vector<ll> a, int n) {
	unordered_map<ll, int> mp;
	int sum = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		// sub-array with 0 to i
		if (sum == 0) ++ans;
		// When we get the same sum again => somewhere a zero sum subarray would have occured
		if (mp.count(sum) == 1) ans += mp[sum];
		mp[sum]++;
	}
	return ans;
}