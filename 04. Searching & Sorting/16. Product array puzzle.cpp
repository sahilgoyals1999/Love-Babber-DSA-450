// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#

// T.C => O(2*n), S.C => O(2*n)

vector<long long> productExceptSelf(vector<long long>& a, int n) {
	if (n == 1) return { 1 };
	vector<long long> left(n), right(n), ans(n);
	left[0] = a[0];
	right[n - 1] = a[n - 1];
	for (int i = 1; i < n - 1; ++i) {
		left[i] = left[i - 1] * a[i];
		right[n - 1 - i] = right[n - i] * a[n - 1 - i];
	}
	left[n - 1] = left[n - 2] * a[n - 1];
	right[0] = right[1] * a[0];
	ans[0] = right[1];
	ans[n - 1] = left[n - 2];
	for (int i = 1; i < n - 1; ++i) {
		ans[i] = (left[i - 1] * right[i + 1]);
	}
	return ans;
}