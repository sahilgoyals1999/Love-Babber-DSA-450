// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// A simple function to print leaf nodes of a binary tree
void printLeaves(Node* root, vector<int> &ans) {
	if (!root) return;
	printLeaves(root->left, ans);
	// Print it if it is a leaf node
	if (!(root->left) && !(root->right)) ans.push_back(root->data);
	printLeaves(root->right, ans);
}

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root, vector<int> &ans) {
	if (!root) return;
	if (root->left) {
		ans.push_back(root->data);
		printBoundaryLeft(root->left, ans);
	}
	else if (root->right) {
		ans.push_back(root->data);
		printBoundaryLeft(root->right, ans);
	}
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root, vector<int> &ans) {
	if (!root) return;
	if (root->right) {
		printBoundaryRight(root->right, ans);
		ans.push_back(root->data);
	}
	else if (root->left) {
		printBoundaryRight(root->left, ans);
		ans.push_back(root->data);
	}
}

vector<int> printBoundary(Node *root) {
	vector<int> ans;
	if (!root) return ans;
	ans.push_back(root->data);
	// Print the left boundary in top-down manner.
	printBoundaryLeft(root->left, ans);
	// Print all leaf nodes
	printLeaves(root->left, ans);
	printLeaves(root->right, ans);
	// Print the right boundary in bottom-up manner
	printBoundaryRight(root->right, ans);
	return ans;
}