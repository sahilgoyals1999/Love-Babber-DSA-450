// https://practice.geeksforgeeks.org/problems/next-permutation5226/1

// T.C => O(n), S.C => O(1)

vector<int> nextPermutation(int n, vector<int> a) {
	// in reverse order, find the first number which is in increasing
	// (we call it violated number)
	int i;
	for (i = n - 2; i >= 0; --i) {
		if (a[i] < a[i + 1]) break;
	}
	// if violated number is found then find greater or equal number then num[i] from reverse
	if (i >= 0) {
		int j;
		for (j = n - 1; j >= 0; --j) {
			if (a[i] < a[j]) break;
		}
		// after finding swap them
		swap(a[i], a[j]);
	}
	// reverse all the numbers after violated number
	reverse(a.begin() + i + 1, a.end());
	return a;
}