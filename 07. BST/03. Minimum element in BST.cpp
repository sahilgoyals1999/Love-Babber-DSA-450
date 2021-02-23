// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

// T.C => O(h), S.C => O(1)

int minValue(Node* root) {
	if (!root) return -1;
	while (root->left) {
		root = root->left;
	}
	return root->data;
}