// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

// T.C => O(n), S.C => O(1)

int solve(Node *root) {
	if (!root) return 0;
	int d = root->data;
	int lsum = solve(root->left);
	int rsum = solve(root->right);
	root->data = lsum + rsum;
	return d + root->data;
}

void toSumTree(Node *root) {
	solve(root);
}