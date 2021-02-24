// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// T.C => O(n), S.C => O(1)

void inorder(Node *root, int &k, int &ans) {
	if (!root || k < 0) return;
	inorder(root->right, k, ans);
	--k;
	if (k == 0) {
		ans = root->data;
		return;
	}
	inorder(root->left, k, ans);
}

int kthLargest(Node *root, int k) {
	int ans = -1;
	// inorder in reverse order
	inorder(root, k, ans);
	return ans;
}