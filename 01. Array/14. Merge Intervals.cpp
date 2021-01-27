// https://leetcode.com/problems/merge-intervals/

// T.C => O(n*log(n)), S.C => O(1)

vector<vector<int>> merge(vector<vector<int>>& A) {
	int n = A.size();
	vector<vector<int>> ans;
	if (n == 0) return ans;
	sort(A.begin(), A.end());
	ans.push_back(A[0]);
	for (int i = 1; i < n; ++i) {
		int m = ans.size();
		if (ans[m - 1][1] < A[i][0]) {
			ans.push_back(A[i]);
		} else {
			ans[m - 1][1] = max(ans[m - 1][1], A[i][1]);
		}
	}
	return ans;
}