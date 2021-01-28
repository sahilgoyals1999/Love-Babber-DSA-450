// https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/

// T.C => O(min(log(n), log(m))), S.C => O(1)

// to find median of two integers
float MO2(int a, int b) {
	return (a + b) / 2.0;
}

// to find median of three integers
float MO3(int a, int b, int c) {
	return a + b + c - max({a, b, c}) - min({a, b, c});
}

// to find a median of four integers
float MO4(int a, int b, int c, int d) {
	return (a + b + c + d - max({a, b, c, d}) - min({a, b, c, d})) / 2.0;
}

// to find median of single sorted array
float medianSingle(int a[], int n) {
	if (n == 0) return -1;
	if (n % 2 == 0) return (double)(a[n / 2] + a[n / 2 - 1]) / 2;
	return a[n / 2];
}

// assumes that n <= m
float findMedianUtil(int A[], int n, int B[], int m) {
	// If smaller array is empty, return median from second array
	if (n == 0) return medianSingle(B, m);
	// If the smaller array has only one element
	if (n == 1) {
		// Case 1: If the larger array also has one element, simply call MO2()
		if (m == 1) return MO2(A[0], B[0]);
		// Case 2: If the larger array has odd number of elements,
		// then consider the middle 3 elements of larger array and
		// the only element of smaller array.
		if (m & 1) return MO2(B[m / 2], MO3(A[0], B[m / 2 - 1], B[m / 2 + 1]));
		// Case 3: If the larger array has even number of element,
		// then median will be one of the following 3 elements
		// The middle two elements of larger array and the only element of smaller array
		return MO3(B[m / 2], B[m / 2 - 1], A[0]);
	}
	// If the smaller array has two elements
	else if (n == 2) {
		// Case 4: If the larger array also has two elements, simply call MO4()
		if (m == 2) return MO4(A[0], A[1], B[0], B[1]);
		// Case 5: If the larger array has odd number of elements,
		// then median will be one of the following 3 elements
		// 1. Middle element of larger array
		// 2. Max of first element of smaller array and element just before the middle in bigger array
		// 3. Min of second element of smaller array and element just after the middle in bigger array
		if (m & 1) return MO3(B[m / 2], max(A[0], B[m / 2 - 1]), min(A[1], B[m / 2 + 1]));
		// Case 6: If the larger array has even number of elements,
		// then median will be one of the following 4 elements
		// 1) & 2) The middle two elements of larger array
		// 3) Max of first element of smaller array and element just before the first middle element in bigger array
		// 4. Min of second element of smaller array and element just after the second middle in bigger array
		return MO4(B[m / 2], B[m / 2 - 1], max(A[0], B[m / 2 - 2]), min(A[1], B[m / 2 + 1]));
	}
	int idxA = (n - 1) / 2;
	int idxB = (m - 1) / 2;
	// if A[idxA] <= B[idxB], then median must exist in A[idxA....] and B[....idxB]
	if (A[idxA] <= B[idxB]) return findMedianUtil(A + idxA, n / 2 + 1, B, m - idxA);
	// if A[idxA] > B[idxB], then median must exist in A[...idxA] and B[idxB....]
	return findMedianUtil(A, n / 2 + 1, B + idxA, m - idxA);
}

float findMedian(int A[], int n, int B[], int m) {
	if (n > m) return findMedianUtil(B, m, A, n);
	return findMedianUtil(A, n, B, m);
}