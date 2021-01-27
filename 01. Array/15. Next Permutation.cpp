// https://leetcode.com/problems/next-permutation/

// T.C => O(n), S.C => O(1)

void nextPermutation(vector<int>& num) {
	int n = num.size();
	if (n == 0) return;
	// in reverse order, find the first number which is in increasing
	// (we call it violated number)
	int i;
	for (i = n - 2; i >= 0; --i) {
		if (num[i] < num[i + 1]) break;
	}
	// if violated number is found then
	// find greater or equal number then num[i] from reverse
	if (i >= 0) {
		int j;
		for (j = n - 1; j >= 0; --j) {
			if (num[i] < num[j]) break;
		}
		// after finding swap them
		swap(num[i], num[j]);
	}
	// reverse all the numbers after violated number
	reverse(num.begin() + i + 1, num.end());
}