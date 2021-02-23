// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

// T.C => O(n), S.C => O(n)

vector<int> topView(struct Node *root) {
	vector<int> ans;
	// queue for holding nodes and their horizontal distance from the root node
	queue<pair<Node*, int>> q;
	// pushing root node with distance 0
	q.push(make_pair(root, 0));
	// hd => currect node's horizontal distance from root node
	// l => currect left min horizontal distance (or max in magnitude) so far from the root node
	// r => currect right max horizontal distance so far from the root node
	int hd = 0, l = 0, r = 0;
	// stack is for holding left node's data because
	// they will appear in reverse order that is why using stack
	stack<int> left;
	// vector is for holding right node's data
	vector<int> right;
	while (!q.empty()) {
		Node *node = q.front().first;
		hd = q.front().second;
		q.pop();
		if (hd < l) {
			left.push(node->data);
			l = hd;
		}
		else if (hd > r) {
			right.push_back(node->data);
			r = hd;
		}
		if (node->left) q.push(make_pair(node->left, hd - 1));
		if (node->right) q.push(make_pair(node->right, hd + 1));
	}
	// printing the left node's data in reverse order
	while (!left.empty()) {
		ans.push_back(left.top());
		left.pop();
	}
	// then printing the root node's data
	ans.push_back(root->data);
	// finally printing the right node's data
	for (auto &x : right) {
		ans.push_back(x);
	}
	return ans;
}
