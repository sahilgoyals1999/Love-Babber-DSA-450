// https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/

// T.C => O(n), S.C => O(1)

// temporary node to keep track of Node returned from previous recursive call during backtrack
Node* temp = NULL;

// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k) {
	if (!root) return NULL;
	if (root->data == node ||
	    (temp = kthAncestorDFS(root->left, node, k)) ||
	    (temp = kthAncestorDFS(root->right, node, k))) {
		if (k > 0) --k;
		else if (k == 0) {
			// print the kth ancestor
			cout << root->data;
			// return NULL to stop further backtracking
			return NULL;
		}
		// return current node to previous call
		return root;
	}
}