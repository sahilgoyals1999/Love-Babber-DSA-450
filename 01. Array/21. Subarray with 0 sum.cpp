// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

// if we again encouter the same sum it means
// at some point sum become zero previously
// T.C => O(n), S.C => O(n)

bool subArrayExists(int a[], int n) {
	unordered_map<long, int> mp;
	long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum == 0 || mp.count(sum) == 1) return true;
		mp[sum] = 1;
	}
	return false;
}