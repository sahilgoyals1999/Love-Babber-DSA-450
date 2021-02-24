// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// T.C => O(n), S.C => O(1)

// Give the function a bound the maximum number it will handle.
// The left recursion will take the elements smaller than node->val
// The right recursion will take the remaining elements smaller than bound

TreeNode* solve(vector<int> &A, int &index, int bound) {
	if (index >= A.size() || A[index] > bound) return NULL;
	TreeNode* root = new TreeNode(A[index]);
	index++;
	root->left = solve(A, index, root->val);
	root->right = solve(A, index, bound);
	return root;
}

TreeNode* bstFromPreorder(vector<int>& A) {
	int index = 0;
	return solve(A, index, INT_MAX);
}