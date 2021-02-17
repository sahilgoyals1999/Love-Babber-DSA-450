// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

// T.C => O(n), S.C => O(1)

void solve(Node *root, int level, int &max_level, vector<int> &ans) {
	if (!root) return;
	// If this is the first node of its level
	if (level > max_level) {
		ans.push_back(root->data);
		max_level = level;
	}
	solve(root->left, level + 1, max_level, ans);
	solve(root->right, level + 1, max_level, ans);
}

vector<int> leftView(Node *root) {
	vector<int> ans;
	int max_level = 0, level = 1;
	solve(root, level, max_level, ans);
	return ans;
}