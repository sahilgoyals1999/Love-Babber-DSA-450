// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

// T.C => O(n), S.C => O(n)

vector<int> reverseLevelOrder(Node *root) {
	vector<int> ans;
	if (!root) return ans;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = q.size();
		vector<int> v;
		while (sz > 0) {
			Node *node = q.front();
			q.pop();
			v.push_back(node->data);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
			--sz;
		}
		ans.insert(ans.begin(), v.begin(), v.end());
	}
	return ans;
}