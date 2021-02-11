// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#

// Moore Voting Algorithm
// T.C => O(2*n), S.C => O(1)

int majorityElement(int a[], int n) {
	int count = 0, candidate = 0;
	for (int i = 0; i < n; ++i) {
		if (count == 0) {
			candidate = a[i];
		}
		if (a[i] == candidate) ++count;
		else --count;
	}
	count = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == candidate) ++count;
	}
	return count > n / 2 ? candidate : -1;
}