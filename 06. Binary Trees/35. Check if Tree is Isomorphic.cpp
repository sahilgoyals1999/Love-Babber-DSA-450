// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1

// T.C => O(min(min(m,n)))

bool isIsomorphic(Node *n1, Node *n2) {
	// Both roots are NULL, trees isomorphic by definition
	if (!n1 && !n2) return true;
	// Exactly one of the n1 and n2 is NULL, trees not isomorphic
	if (!n1 || !n2) return false;
	if (n1->data != n2->data) return false;
	// There are two possible cases for n1 and n2 to be isomorphic
	// Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
	// Both of these subtrees have to be isomorphic, hence the &&
	// Case 2: The subtrees rooted at these nodes have been "Flipped"
	return (isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
	       (isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left));
}