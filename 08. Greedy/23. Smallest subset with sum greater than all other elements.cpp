// https://www.geeksforgeeks.org/smallest-subset-sum-greater-elements/

// T.C => (n*log(n)), S.C => O(1)

// function to find minimum elements needed.
int minElements(int a[], int n) {
	// calculating HALF of array sum
	int halfSum = 0;
	for (int i = 0; i < n; ++i) {
		halfSum = halfSum + a[i];
	}
	halfSum = halfSum / 2;
	// sort the array in descending order.
	sort(a, a + n, greater<int>());
	int res = 0, curr_sum = 0;
	for (int i = 0; i < n; ++i) {
		curr_sum += a[i];
		res++;
		// current sum greater than sum
		if (curr_sum > halfSum) return res;
	}
	return res;
}