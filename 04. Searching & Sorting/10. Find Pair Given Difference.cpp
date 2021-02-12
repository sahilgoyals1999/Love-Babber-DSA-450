// https://practice.geeksforgeeks.org/problems/find-pair-given-difference/0#

// T.C => O(n*log(n)), S.C => O(1)

int solve(int a[], int n, int x) {
	sort(a, a + n);
	int i = 0, j = 1;
	while (i < n && j < n) {
		if (i != j && a[j] - a[i] == x) return 1;
		else if (a[j] - a[i] < x) j++;
		else i++;
	}
	return -1;
}