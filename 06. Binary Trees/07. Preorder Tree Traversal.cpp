// https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/

// Recursive function to perform preorder traversal on the tree
// T.C => O(n), S.C => O(1)
void preorder(Node *root) {
	// if the current node is empty
	if (!root) return;
	// Display the data part of the root (or current node)
	cout << root->data << " ";
	// Traverse the left subtree
	preorder(root->left);
	// Traverse the right subtree
	preorder(root->right);
}

// Iterative function to perform preorder traversal on the tree
// T.C => O(n), S.C => O(n)
void preorderIterative(Node *root) {
	// return if the tree is empty
	if (!root) return;
	// create an empty stack and push the root node
	stack<Node*> s;
	s.push(root);
	// loop till stack is empty
	while (!stack.empty()) {
		// pop a node from the stack and print it
		Node *cur = s.top();
		s.pop();
		cout << cur->data << " ";
		// push the right child of the popped node into the stack
		if (cur->right) s.push(cur->right);
		// push the left child of the popped node into the stack
		if (cur->left) s.push(cur->left);
		// the right child must be pushed first so that the left child
		// is processed first (FIFO order)
	}
}