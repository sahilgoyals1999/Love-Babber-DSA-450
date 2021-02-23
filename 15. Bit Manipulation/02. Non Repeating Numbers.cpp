// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

// T.C => O(n), S.C => O(1)

vector<int> singleNumber(vector<int>& a) {
	int n = a.size();
	// Will hold Xor of all elements
	int Xor = a[0];
	// Get the Xor of all elements
	for (int i = 1; i < n; ++i) {
		Xor ^= a[i];
	}
	// Will have only single set bit of Xor, Get the rightmost set bit in set_bit_no
	int set_bit_no = Xor & ~(Xor - 1);
	vector<int> ans(2, 0);
	// Now divide elements in two sets by comparing rightmost set bit of Xor with bit at same position in each element.
	for (int i = 0; i < n; ++i) {
		// Xor of first set
		if (a[i] & set_bit_no) {
			ans[0] ^= a[i];
		}
		// Xor of second set
		else {
			ans[1] ^= a[i];
		}
	}
	if (ans[0] > ans[1]) swap(ans[0], ans[1]);
	return ans;
}