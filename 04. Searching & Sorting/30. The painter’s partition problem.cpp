// https://www.geeksforgeeks.org/painters-partition-problem-set-2/

// T.C => O(n*log(sum(a[])), S.C => O(1)

// return the maximum element from the array
int getMax(int a[], int n) {
	int mx = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (a[i] > mx) {
			mx = a[i];
		}
	}
	return mx;
}

// return the sum of the elements in the array
int getSum(int a[], int n) {
	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += a[i];
	}
	return total;
}

// find minimum required painters for given maxlen
// which is the maximum length a painter can paint
int numberOfPainters(int a[], int n, int maxLen) {
	int total = 0, numPainters = 1;
	for (int i = 0; i < n; ++i) {
		total += a[i];
		if (total > maxLen) {
			// for next count
			total = a[i];
			numPainters++;
		}
	}
	return numPainters;
}

int partition(int a[], int n, int k) {
	int lo = getMax(a, n);
	int hi = getSum(a, n);
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		int requiredPainters = numberOfPainters(a, n, mid);
		// find better optimum in lower half here mid is included
		// because we may not get anything better
		if (requiredPainters <= k) {
			hi = mid;
		}
		// find better optimum in upper half here mid is excluded because it gives
		// required Painters > k, which is invalid
		else {
			lo = mid + 1;
		}
	}
	return lo;
}