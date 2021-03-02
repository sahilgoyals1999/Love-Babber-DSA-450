// https://www.geeksforgeeks.org/maximum-product-subset-array/

// T.C => O(n), S.C => O(1)

int maxProductSubset(int a[], int n) {
	if (n == 1) return a[0];
	// Find count of negative numbers, count of zeros,
	// negative number with least absolute value
	// and product of non-zero numbers
	int max_neg = INT_MIN, count_neg = 0, count_zero = 0, prod = 1;
	for (int i = 0; i < n; ++i) {
		// If number is 0, we don't multiply it with product.
		if (a[i] == 0) {
			count_zero++;
			continue;
		}
		// Count negatives and find max_neg
		if (a[i] < 0) {
			count_neg++;
			max_neg = max(max_neg, a[i]);
		}
		prod = prod * a[i];
	}
	// If there are all zeros
	if (count_zero == n) return 0;
	// If there are odd number of negative numbers
	if (count_neg & 1) {
		// Exceptional case: There is only negative and all other are zeros
		if (count_neg == 1 && count_zero == n - 1) return 0;
		// Otherwise result is product of all non-zeros divided by
		// negative number with least absolute value
		prod = prod / max_neg;
	}
	return prod;
}