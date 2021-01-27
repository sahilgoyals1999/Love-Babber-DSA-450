// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

// T.C => O(n), S.C => O(1)

void shiftall(int a[], int left, int right) {
	while (left <= right) {
		// if the left and the right elements are negative
		if (a[left] < 0 && a[right] < 0) left++;
		// if the left pointer element is positive and the right pointer element is negative
		else if (a[left] > 0 && a[right] < 0) {
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
		}
		// if both the elements are positive
		else if (a[left] > 0 && a[right] > 0) right--;
		else {
			left++;
			right--;
		}
	}
}