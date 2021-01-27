// https://practice.geeksforgeeks.org/problems/common-elements1132/1

// T.C => O(n1+n2+n3), S.C => O(1)

vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
	vector<int> ans;
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2 && k < n3) {
		if (A[i] == B[j] && B[j] == C[k]) {
			if (ans.size() == 0 || ans[ans.size() - 1] != A[i]) {
				ans.push_back(A[i]);
			}
			++i;
			++j;
			++k;
		} else {
			int mn = min({A[i], B[j], C[k]});
			if (A[i] == mn) ++i;
			if (B[j] == mn) ++j;
			if (C[k] == mn) ++k;
		}
	}
	return ans;
}