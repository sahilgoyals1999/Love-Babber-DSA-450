// https://practice.geeksforgeeks.org/problems/sum-tree/1

// T.C => O(n), S.C => O(1)

int solve(Node *root, bool &ans) {
	if (!root) return 0;
	if (!root->left && !root->right) return root->data;
	int sum = 0;
	sum += solve(root->left, ans);
	sum += solve(root->right, ans);
	if (root->data != sum) {
		ans = false;
	}
	return sum + root->data;
}

bool isSumTree(Node* root) {
	bool ans = true;
	solve(root, ans);
	return ans;
}