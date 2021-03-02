// https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/

// T.C => O(n*log(n)), S.C => O(n)

int MaxSumDifference(int a[], int n) {
	// final sequence stored in the vector
	vector<int> finalSequence;
	// sort the original array so that we can retrieve
	// the large elements from the end of array elements
	sort(a, a + n);
	// In this loop first we will insert one smallest element not entered
	// till that time in final sequence and then enter a highest element
	// (not entered till that time) in final sequence so that we
	// have large difference value.
	// This process is repeated till all array
	// has completely entered in sequence.
	// Here, we have loop till n/2.
	for (int i = 0; i < n / 2; ++i) {
		finalSequence.push_back(a[i]);
		finalSequence.push_back(a[n - i - 1]);
	}
	// If there are odd elements, push the middle element at the end.
	if (n % 2 != 0) finalSequence.push_back(a[n / 2]);
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans += abs(finalSequence[i] - finalSequence[i + 1]);
	}
	// absolute difference of last element and 1st element
	ans += abs(finalSequence[n - 1] - finalSequence[0]);
	// return the value
	return ans;
}