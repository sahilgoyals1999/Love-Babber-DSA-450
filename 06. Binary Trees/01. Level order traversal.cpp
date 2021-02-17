// https://practice.geeksforgeeks.org/problems/level-order-traversal/1

// T.C => O(n), S.C => O(n)

vector<int> levelOrder(Node* node) {
	vector<int> ans;
	if (!node) return ans;
	queue<Node*> q;
	q.push(node);
	while (!q.empty()) {
		Node *root = q.front();
		q.pop();
		ans.push_back(root->data);
		if (root->left) q.push(root->left);
		if (root->right) q.push(root->right);
	}
	return ans;
}