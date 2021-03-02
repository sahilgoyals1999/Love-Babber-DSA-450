// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1#

// T.C => O(O(log2 N * log5 N)), S.C => O(1)

int solve(int x) {
	int ans = 0;
	while (x > 0) {
		x /= 5;
		ans += x;
	}
	return ans;
}

int findNum(int n) {
	int l = 0, r = 5e4, ans = INT_MAX;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (solve(mid) >= n) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}