// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

// T.C => O(n), S.C => O(1)

int height(Node* root, int &ans) {
	if (!root) return 0;
	int lh = height(root->left, ans);
	int rh = height(root->right, ans);
	ans = max(ans, 1 + lh + rh);
	return 1 + max(lh, rh);
}

int diameter(Node* root) {
	if (!root) return 0;
	int ans = 0;
	height(root, ans);
	return ans;
}