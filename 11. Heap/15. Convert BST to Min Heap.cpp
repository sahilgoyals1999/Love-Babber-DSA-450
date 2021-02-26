// https://www.geeksforgeeks.org/convert-bst-min-heap/

// T.C => O(n), S.C => O(n)

// function for the inorder traversal of the tree so as to store
// the node values in 'v' in sorted order
void inorderTraversal(Node *root, vector<int>& v) {
	if (!root) return;
	// first recur on left subtree
	inorderTraversal(root->left, v);
	// then copy the data of the node
	v.push_back(root->data);
	// now recur for right subtree
	inorderTraversal(root->right, v);
}

// function to convert the given BST to MIN HEAP performs preorder traversal of the tree
void BSTToMinHeap(Node *root, vector<int> v, int &i) {
	if (!root) return;
	// first copy data at index 'i' of 'v' to the node
	root->data = v[i++];
	// then recur on left subtree
	BSTToMinHeap(root->left, v, i);
	// now recur on right subtree
	BSTToMinHeap(root->right, v, i);
}

// utility function to convert the given BST to MIN HEAP
void convertToMinHeapUtil(Node *root) {
	// vector to store the data of all the nodes of the BST
	vector<int> v;
	int i = 0;
	// inorder traversal to populate 'v'
	inorderTraversal(root, v);
	// BST to MIN HEAP conversion
	BSTToMinHeap(root, v, i);
}