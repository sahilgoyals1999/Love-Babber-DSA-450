// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

// T.C => O(n^2), S.C => O(1)

long long countTriplets(long long a[], int n, long long sum) {
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n - 2; ++i) {
		int j = i + 1, k = n - 1;
		while (j < k) {
			if (a[i] + a[j] + a[k] >= sum) {
				--k;
			}
			else {
				ans += (k - j);
				++j;
			}
		}
	}
	return ans;
}