// https://leetcode.com/problems/delete-node-in-a-bst/

// T.C => O(h), S.C => O(1)

TreeNode* deleteNode(TreeNode* root, int key) {
	if (!root) return root;
	if (root->val == key) {
		if (!root->right) {
			TreeNode* left = root->left;
			delete root;
			return left;
		}
		else {
			TreeNode* right = root->right;
			// find left most element and swap them
			while (right->left) {
				right = right->left;
			}
			swap(root->val, right->val);
			root->right = deleteNode(root->right, key);
		}
	}
	else if (root->val > key) {
		root->left = deleteNode(root->left, key);
	}
	else {
		root->right = deleteNode(root->right, key);
	}
	return root;
}