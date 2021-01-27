// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// T.C => O(n), S.C => O(1)

int maxSubarraySum(int a[], int n) {
	int ans = INT_MIN, sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}
	return ans;
}