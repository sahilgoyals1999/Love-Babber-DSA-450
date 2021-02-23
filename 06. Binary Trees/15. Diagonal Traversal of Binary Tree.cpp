// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1#

// T.C => O(n), S.C => O(n)

void solve(Node *root, int d, int &mx, auto &mp) {
	if (!root) return;
	mx = max(mx, d);
	mp[d].push_back(root->data);
	solve(root->left, d + 1, mx, mp);
	solve(root->right, d, mx, mp);
}


vector<int> diagonal(Node *root) {
	unordered_map<int, vector<int>> mp;
	vector<int> ans;
	int d = 0, mx = 0;
	solve(root, 0, mx, mp);
	for (int i = 0; i <= mx; ++i) {
		ans.insert(ans.end(), mp[i].begin(), mp[i].end());
	}
	return ans;
}