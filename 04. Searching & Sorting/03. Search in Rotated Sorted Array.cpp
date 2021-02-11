// https://leetcode.com/problems/search-in-rotated-sorted-array/

// T.C => O(2*log(n)), S.C => O(1)

int findPivot(vector<int> a, int low, int high) {
	if (low > high) return -1;
	if (low == high) return low;
	int mid = low + (high - low) / 2;
	if (mid + 1 <= high && a[mid] > a[mid + 1]) return mid;
	if (mid - 1 >= low && a[mid - 1] > a[mid]) return (mid - 1);
	if (a[low] >= a[mid]) return findPivot(a, low, mid - 1);
	return findPivot(a, mid + 1, high);
}

int binarySearch(vector<int> a, int low, int high, int key) {
	if (high < low) return -1;
	int mid = low + (high - low) / 2;
	if (a[mid] == key) return mid;
	if (a[mid] < key) return binarySearch(a, mid + 1, high, key);
	return binarySearch(a, low, mid - 1, key);
}

int search(vector<int>& a, int key) {
	int n = a.size();
	int pivot = findPivot(a, 0, n - 1);
	// [4,5,6,7,0,1,2] => a[pivot] = 7
	if (pivot == -1) return binarySearch(a, 0, n - 1, key);
	if (a[pivot] == key) return pivot;
	if (a[0] <= key) return binarySearch(a, 0, pivot - 1, key);
	return binarySearch(a, pivot + 1, n - 1, key);
}