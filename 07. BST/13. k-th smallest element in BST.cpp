// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

// T.C => O(n), S.C => O(1)

void inorder(Node *root, int &k, int &ans) {
	if (!root || k < 0) return;
	inorder(root->left, k, ans);
	--k;
	if (k == 0) {
		ans = root->data;
		return;
	}
	inorder(root->right, k, ans);
}

int KthSmallestElement(Node *root, int k) {
	int ans = -1;
	inorder(root, k, ans);
	return ans;
}