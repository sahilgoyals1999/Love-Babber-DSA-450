// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

// Pull all smaller elements in a and larger elements in b then sort both the array
// T.C => O(max(n, m) + n*log(n) + m*log(m)), S.C => O(1)

void merge(int a[], int b[], int n, int m) {
	int i = n - 1, j = 0;
	// comare last element of a with first elemennt of b
	while (i >= 0 && j < m) {
		if (a[i] > b[j]) {
			swap(a[i], b[j]);
		}
		i--;
		j++;
	}
	sort(a, a + n);
	sort(b, b + m);
}