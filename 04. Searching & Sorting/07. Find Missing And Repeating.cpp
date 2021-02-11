// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

// T.C => O(n), S.C => O(1)

int *findTwoElement(int *a, int n) {
	int *ans = new int[2];
	for (int i = 0; i < n; ++i) {
		int x = abs(a[i]);
		if (a[x - 1] > 0) a[x - 1] = -a[x - 1];
		else ans[0] = x;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) ans[1] = i + 1;
	}
	return ans;
}