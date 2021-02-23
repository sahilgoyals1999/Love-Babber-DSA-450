// https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/

// T.C => O(h), S.C => O(1)

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
	if (!root) return;
	// If key is present at root
	if (root->key == key) {
		// the maximum value in left subtree is predecessor
		if (root->left) {
			Node* temp = root->left;
			while (temp->right) {
				temp = temp->right;
			}
			pre = temp ;
		}
		// the minimum value in right subtree is successor
		if (root->right) {
			Node* temp = root->right ;
			while (temp->left) {
				temp = temp->left;
			}
			suc = temp ;
		}
		return;
	}
	// If key is smaller than root's key, go to left subtree
	if (root->key > key) {
		suc = root ;
		findPreSuc(root->left, pre, suc, key) ;
	}
	else {// go to right subtree
		pre = root ;
		findPreSuc(root->right, pre, suc, key) ;
	}
}