// https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

// T.C => O(n), S.C => O(1)

int findMinOps(int a[], int n) {
	int ans = 0, left = 0, right = n - 1;
	while (left <= right) {
		// If corner elements are same, problem reduces a[left+1....right-1]
		if (a[left] == a[right]) {
			left++;
			right--;
		}
		// If left element is greater, then we merge right two elements
		else if (a[i] > a[j]) {
			// need to merge from tail.
			right--;
			a[right] += a[right + 1] ;
			ans++;
		}
		// Else we merge left two elements
		else {
			left++;
			a[i] += a[i - 1];
			ans++;
		}
	}
	return ans;
}