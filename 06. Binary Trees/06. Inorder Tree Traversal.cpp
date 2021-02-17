// https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/

// Recursive function to perform inorder traversal on the tree
// T.C => O(n), S.C => O(1)
void inorder(Node *root) {
	// return if the current node is empty
	if (!root) return;
	// Traverse the left subtree
	inorder(root->left);
	// Display the data part of the root (or current node)
	cout << root->data << " ";
	// Traverse the right subtree
	inorder(root->right);
}

// Iterative function to perform inorder traversal on the tree
// T.C => O(n), S.C => O(n)
void inorderIterative(Node *root) {
	// create an empty stack
	stack<Node*> s;
	// start from the root node (set current node to the root node)
	Node *cur = root;
	// if the current node is null and the stack is also empty, we're done
	while (!s.empty() || cur) {
		// if the current node exists, push it into the stack (defer it) and move to its left child
		if (cur) {
			s.push(cur);
			cur = cur->left;
		}
		else {
			// otherwise, if the current node is null, pop an element from the stack,
			// print it, and finally set the current node to its right child
			cur = s.top();
			s.pop();
			cout << cur->data << " ";
			cur = cur->right;
		}
	}
}