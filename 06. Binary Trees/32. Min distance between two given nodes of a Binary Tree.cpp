// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

// T.C => O(n), S.C => O(1)

Node* LCA(Node* root, int p, int q) {
	if (!root || root->data == p || root->data == q) return root;
	Node *left = LCA(root->left, p, q);
	Node *right = LCA(root->right, p, q);
	if (!left) return right;
	else if (!right) return left;
	else return root;
}

int findLevel(Node *root, int k, int level) {
	if (!root) return -1;
	if (root->data == k) return level;
	int left = findLevel(root->left, k, level + 1);
	if (left == -1) return findLevel(root->right, k, level + 1);
	return left;
}

int findDist(Node* root, int a, int b) {
	Node* lca = LCA(root, a , b);
	int d1 = findLevel(lca, a, 0);
	int d2 = findLevel(lca, b, 0);
	return d1 + d2;
}