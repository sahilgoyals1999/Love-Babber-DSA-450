// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1#

// T.C => O(n), S.C => O(1)

int sb(int a[], int n, int x) {
	int sum = 0, ans = n + 1;
	int start = 0, end = 0;
	while (end < n) {
		// Keep adding array elements while current sum is smaller than x
		while (sum <= x && end < n) {
			sum += a[end];
			end++;
		}
		// If current sum becomes greater than x.
		while (sum > x && start < n) {
			ans = min(ans, end - start);
			sum -= a[start];
			start++;
		}
	}
	return (ans > n) ? 0 : ans;
}