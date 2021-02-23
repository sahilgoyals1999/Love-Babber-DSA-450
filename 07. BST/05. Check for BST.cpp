// https://practice.geeksforgeeks.org/problems/check-for-bst/1#

// T.C => O(n), S.C => O(1)

void solve(Node *root, int mn, int mx, bool &ans) {
	if (!root) return;
	if (root->data <= mn || root->data >= mx) {
		ans = false;
	}
	solve(root->left, mn, root->data, ans);
	solve(root->right, root->data, mx, ans);
}

bool isBST(Node* root) {
	int mn = INT_MIN, mx = INT_MAX;
	bool ans = true;
	solve(root, mn, mx, ans);
	return ans;
}