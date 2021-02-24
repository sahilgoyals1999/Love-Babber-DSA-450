// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

// T.C => O(n*log(n)), S.C => O(1)

bool search(Node* root, int value) {
	if (!root) return false;
	if (root->data == value) return true;
	else if (root->data > value) {
		return search(root->left, value);
	}
	return search(root->right, value);
}

int countPairs(Node* root1, Node* root2, int x) {
	if (!root1) return 0;
	else if (search(root2, x - root1->data)) {
		return 1 + countPairs(root1->left, root2, x) + countPairs(root1->right, root2, x);
	}
	return countPairs(root1->left, root2, x) + countPairs(root1->right, root2, x);
}