// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

// T.C => O(n), S.C => O(1)

int height(Node *root) {
	if (!root) return 0;
	int lh = height(root->left);
	if (lh == -1) return -1;
	int rh = height(root->right);
	if (rh == -1) return -1;
	if (abs(lh - rh) > 1) return -1;
	return 1 + max(lh, rh);
}

bool isBalanced(Node *root) {
	return height(root) != -1;
}