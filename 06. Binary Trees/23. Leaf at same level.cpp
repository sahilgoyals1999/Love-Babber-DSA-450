// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#

// T.C => O(n), S.C => O(1)

int solve(Node* root, bool &ans) {
	if (!root) return 0;
	int lheight = solve(root->left, ans);
	int rheight = solve(root->right, ans);
	if (root->left && root->right && lheight != rheight) {
		ans = false;
	}
	return 1 + max(lheight, rheight);
}

bool check(Node *root) {
	bool ans = true;
	solve(root, ans);
	return ans;
}