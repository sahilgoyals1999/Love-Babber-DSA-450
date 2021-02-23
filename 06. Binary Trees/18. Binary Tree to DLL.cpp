// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#

// T.C => O(n), S.C => O(1)

// While doing inorder traversal,
// keep track of the previously visited node in a variable say prev.
// For every visited node, make it next of prev and previous of this node as prev.

void solve(Node *root, Node *&head, Node *&prev) {
	// Base case
	if (!root) return;
	// Recursively convert left subtree
	solve(root->left, head, prev);
	// Now convert this node
	if (!prev) {
		head = root;
	}
	else {
		// Connect prev and root node (prev <-> root)
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	// Finally convert right subtree
	solve(root->right, head, prev);
}

Node* bToDLL(Node *root) {
	Node *head = NULL, *prev = NULL;
	solve(root, head, prev);
	return head;
}