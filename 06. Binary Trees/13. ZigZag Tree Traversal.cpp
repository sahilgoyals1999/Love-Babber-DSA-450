// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// T.C => O(n), S.C => O(n)

vector<int> zigZagTraversal(Node* root) {
	vector<int> ans;
	if (!root) return ans;
	queue<Node*> q;
	q.push(root);
	bool c = true;                     // c == true => lefToRight else rightToLeft
	while (!q.empty()) {
		int sz = q.size();
		vector<int> sub(sz);
		for (int i = 0; i < sz; ++i) {
			Node* tp = q.front();
			q.pop();
			if (c) sub[i] = tp->data;
			else sub[sz - 1 - i] = tp->data;
			if (tp->left) q.push(tp->left);
			if (tp->right) q.push(tp->right);
		}
		c = !c;
		ans.insert(ans.end(), sub.begin(), sub.end());
	}
	return ans;
}