// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// T.C => O(n), S.C => O(1)
// Buy at min and sell at max after it

int maxProfit(vector<int>& A) {
	int n = A.size();
	int mn = INT_MAX, ans = 0;
	for (int i = 0; i < n; ++i) {
		mn = min(mn, A[i]);
		ans = max(ans, A[i] - mn);
	}
	return ans;
}