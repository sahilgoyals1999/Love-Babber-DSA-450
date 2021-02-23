// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

// Searching
// T.C => O(h), S.C => O(1)
Node* search(Node* root, int value) {
	if (!root || root->data == value) return root;
	if (root->key < key) return search(root->right, value);
	return search(root->left, value);
}

// Insertion
// T.C => O(h), S.C => O(1)
Node* insert(Node* root, int value) {
	if (!root) return new Node(value);
	if (value == root->data) return root;
	else if (value > root->data) {
		root->right = insert(root->right, value);
	}
	else {
		root->left = insert(root->left, value);
	}
	return root;
}