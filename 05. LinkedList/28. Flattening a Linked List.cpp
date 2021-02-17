// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// T.C => O(n*m), S.C => O(1)

Node* merge(Node* a, Node* b) {
	if (!a) return b;
	if (!b) return a;
	Node* result;
	if (a->data < b->data) {
		result = a;
		result->bottom = merge(a->bottom, b);
	}
	else {
		result = b;
		result->bottom = merge(a, b->bottom);
	}
	return result;
}

Node *flatten(Node *root) {
	if (!root || !root->next) return root;
	return merge(root, flatten(root->next));
}