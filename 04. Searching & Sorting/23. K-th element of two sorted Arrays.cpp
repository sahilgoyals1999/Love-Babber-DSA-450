// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

// T.C => O(log(n)+log(m)), S.C => O(1)

int kthElement(int a[], int b[], int m, int n, int k) {
	if (k > (m + n) || k < 1) return -1;
	// let m <= n
	if (m > n) return kthElement(b, a, n, m, k);
	// Check if a is empty returning k-th element of b
	if (m == 0) return b[k - 1];
	// Check if k = 1 return minimum of first two elements of both arrays
	if (k == 1) return min(a[0], b[0]);
	// Now the divide and conquer part
	int i = min(m, k / 2);
	int j = min(n, k / 2);
	if (a[i - 1] > b[j - 1]) {
		// Now we need to find only k-j th element since we have found out the lowest j
		return kthElement(a, b + j, m, n - j, k - j);
	}
	// else, Now we need to find only k-i th element since we have found out the lowest i
	return kthElement(a + i, b, m - i, n, k - i);
}