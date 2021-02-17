// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

// T.C => O(n), S.C => O(1)

int height(struct Node* node) {
	if (!node) return 0;
	return 1 + max(height(node->left), height(node->right));
}