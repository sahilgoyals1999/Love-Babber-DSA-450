// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

// T.C => O(n), S.C => O(1)

int getCount(Node *root, int l, int h) {
	if (!root) return 0;
	if (root->data < l && root->data < h) return getCount(root->right, l, h);
	else if (root->data > l && root->data > h) return getCount(root->left, l, h);
	return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
}