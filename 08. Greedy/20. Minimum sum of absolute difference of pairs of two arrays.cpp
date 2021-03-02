// https://www.geeksforgeeks.org/minimum-sum-absolute-difference-pairs-two-arrays/

// T.C => O(n*log(n)), S.C => O(1)

// Returns minimum possible pairwise absolute difference of two arrays.
long long findMinSum(int a[], int b[], int n) {
	// Sort both arrays
	sort(a, a + n);
	sort(b, b + n);
	// Find sum of absolute differences
	long long sum = 0 ;
	for (int i = 0; i < n; ++i) {
		sum += abs(a[i] - b[i]);
	}
	return sum;
}