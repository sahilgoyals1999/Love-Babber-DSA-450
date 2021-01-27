// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// T.C => O(n), S.C => O(1)

void sort012(int a[], int n) {
	int left = 0, right = n - 1, i = 0;
	while (i <= right) {
		if (a[i] == 0) {
			swap(a[i], a[left]);
			++i;
			++left;
		}
		else if (a[i] == 2) {
			swap(a[i], a[right]);
			--right;
		}
		else ++i;
	}
}