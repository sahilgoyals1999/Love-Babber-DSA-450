// https://leetcode.com/problems/search-a-2d-matrix/

// T.C => O(log(n*m)), S.C => O(1)

bool searchMatrix(vector<vector<int>>& a, int x) {
	int n = a.size();
	if (n == 0) return false;
	int m = a[0].size();
	int left = 0, right = n * m - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int r = mid / m;
		int c = mid % m;
		if (a[r][c] == x) return true;
		if (a[r][c] > x) right = mid - 1;
		else left = mid + 1;
	}
	return false;
}