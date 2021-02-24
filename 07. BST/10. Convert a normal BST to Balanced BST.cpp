// https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/

// T.C => O(n), S.C => O(n)

// This function traverse the skewed binary tree and stores its nodes pointers in vector nodes[]
void inorder(Node* root, vector<Node*> &nodes) {
	// Base case
	if (!root) return;
	// Store nodes in Inorder (which is sorted order for BST)
	inorder(root->left, nodes);
	nodes.push_back(root);
	inorder(root->right, nodes);
}

// Recursive function to construct binary tree
Node* solve(vector<Node*> &nodes, int start, int end) {
	// base case
	if (start > end) return NULL;
	// Get the middle element and make it root
	int mid = start + (end - start) / 2;
	Node *root = nodes[mid];
	// Using index in Inorder traversal, construct left and right subtress
	root->left  = solve(nodes, start, mid - 1);
	root->right = solve(nodes, mid + 1, end);
	return root;
}

// This functions converts an unbalanced BST to a balanced BST
Node* buildTree(Node* root) {
	// Store nodes of given BST in sorted order
	vector<Node *> nodes;
	inorder(root, nodes);
	// Constucts BST from nodes[]
	int n = nodes.size();
	return solve(nodes, 0, n - 1);
}