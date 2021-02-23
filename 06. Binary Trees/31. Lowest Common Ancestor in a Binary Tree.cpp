// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

// T.C => O(n), S.C => O(1)

// case 1: if left subtree gives NULL => both of them p and q is not present in the left
// subtree So, result is in the right subtree(both present in the right subtree)
// case 2: if right subtree gives NULL => both of them p and q is not present in the
// right subtree So, result is in the left subtree(both present in the left subtree)
// case 3: if both left and the right subtree gives not NUll than one of them p or q is
// present in the left subtree and other one is present in the right subtree
// So in this case ans is root

Node* lca(Node* root, int p, int q) {
	if (!root || root->data == p || root->data == q) return root;
	Node *left = lca(root->left, p, q);
	Node *right = lca(root->right, p, q);
	if (!left) return right;
	else if (!right) return left;
	else return root;
}