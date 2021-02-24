// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#

// T.C => O(n*log(n)), S.C => O(n)

void inorder(Node* root, vector<int> &in) {
	if (!root) return;
	inorder(root->left, in);
	in.push_back(root->data);
	inorder(root->right, in);
}

void bst(Node* root, vector<int> &in, int &index) {
	if (!root) return;
	bst(root->left, in, index);
	root->data = in[index];
	index++;
	bst(root->right, in, index);
}

Node* binaryTreeToBST(Node *root) {
	// find inorder
	vector<int> in;
	inorder(root, in);
	sort(in.begin(), in.end());
	// assign values to each node
	int index = 0;
	bst(root, in, index);
	return root;
}