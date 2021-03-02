// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

// T.C => O(n*log(sum(a[]))), S.C => O(1)

// function to check if current minimum value is feasible or not.
bool isPossible(int a[], int n, int m, int mn) {
	int studentsRequired = 1;
	int sum = 0;
	// iterate over all books
	for (int i = 0; i < n; ++i) {
		// check if current number of pages are greater than mn
		// that means we will get the result after mid no. of pages
		if (a[i] > mn) return false;
		// count how many students are required to distribute mn pages
		if (sum + a[i] > mn) {
			// increment student count
			studentsRequired++;
			sum = a[i];
			// if students required becomes greater than given no. of students
			if (studentsRequired > m) return false;
		}
		else {
			sum += a[i];
		}
	}
	return true;
}

int findPages(int a[], int n, int m) {
	long sum = 0;
	// return -1 if no. of books is less than no. of students
	if (n < m) return -1;
	// Count total number of pages
	for (int i = 0; i < n; ++i) {
		sum += a[i];
	}
	// initialize start as 0 pages and end as total pages
	int start = 0, end = sum;
	int ans = INT_MAX;
	while (start <= end) {
		// check if it is possible to distribute
		// books by using mid as current minimum
		int mid = start + (end - start) / 2;
		if (isPossible(a, n, m, mid)) {
			// if yes then find the minimum distribution
			ans = min(ans, mid);
			// as we are finding minimum and books are sorted so reduce end
			end = mid - 1;
		}
		else {
			// if not possible means pages should be increased
			start = mid + 1;
		}
	}
	return ans;
}