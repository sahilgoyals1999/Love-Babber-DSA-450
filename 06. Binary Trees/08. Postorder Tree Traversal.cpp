// https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/

// Recursive function to perform postorder traversal on the tree
// T.C => O(n), S.C => O(1)
void postorder(Node *root) {
	// if the current node is empty
	if (!root) return;
	// Traverse the left subtree
	postorder(root->left);
	// Traverse the right subtree
	postorder(root->right);
	// Display the data part of the root (or current node)
	cout << root->data << " ";
}

// Iterative function to perform postorder traversal on the tree
// T.C => O(n), S.C => O(n)
void postorderIterative(Node* root) {
	// create an empty stack and push the root node
	stack<Node*> s;
	s.push(root);
	// create another stack to store postorder traversal
	stack<int> out;
	// loop till stack is empty
	while (!s.empty()) {
		// pop a node from the stack and push the data into the output stack
		Node *cur = s.top();
		s.pop();
		out.push(cur->data);
		// push the left and right child of the popped node into the stack
		if (cur->left) s.push(cur->left);
		if (cur->right) s.push(cur->right);
	}
	// print postorder traversal
	while (!out.empty()) {
		cout << out.top() << " ";
		out.pop();
	}
}
