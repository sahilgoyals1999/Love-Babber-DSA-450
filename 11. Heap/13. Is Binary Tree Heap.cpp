// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

// T.C => O(n), S.C => O(1)

// It should be a complete tree (i.e. all levels except last should be full).
// Every node’s value should be greater than or equal to its child node (considering max-heap).

// This function counts the number of nodes in a binary tree
int countNodes(Node* root) {
	if (!root) return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

// This function checks if the binary tree is complete or not
bool isCompleteUtil(Node* root, int index, int n) {
	// An empty tree is complete
	if (!root) return true;
	// If index assigned to current node is more than number of nodes in tree,
	// then tree is not complete
	if (index >= n) return false;
	// Recur for left and right subtrees
	return (isCompleteUtil(root->left, 2 * index + 1, n) &&
	        isCompleteUtil(root->right, 2 * index + 2, n));
}

// This Function checks the heap property in the tree.
bool isHeapUtil(Node* root) {
	//  Base case : single node satisfies property
	if (!root->left && !root->right) return true;
	// node will be in second last level
	if (!root->right) {
		// check heap property at Node
		// No recursive call, because no need to check last level
		return (root->data >= root->left->data);
	}
	else {
		// Check heap property at Node and
		// Recursive check heap, property at left and right subtree
		if (root->data >= root->left->data && root->data >= root->right->data) {
			return ((isHeapUtil(root->left)) && (isHeapUtil(root->right)));
		}
		else return false;
	}
}

bool isHeap(Node *root) {
	int n = countNodes(root), index = 0;
	return (isCompleteUtil(root, index, n) && isHeapUtil(root));
}