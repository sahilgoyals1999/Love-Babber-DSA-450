// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

// T.C => O(n*log(n), S.C => O(1)

int getMinDiff(int a[], int n, int k) {
	sort(a, a + n);
	int ans = a[n - 1] - a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] >= k) {
			int mx = max(a[i - 1] + k, a[n - 1] - k);
			int mn = min(a[0] + k, a[i] - k);
			ans = min(ans, mx - mn);
		}
	}
	return ans;
}