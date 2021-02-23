// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// T.C => O(n), S.C => O(n)

void solve(Node *node, int dist, int level, auto &map) {
	// base case: empty tree
	if (!node) return;
	// if the current level is more than or equal to the maximum level seen so far
	// for the same horizontal distance or horizontal distance is seen for
	// the first time, update the map
	if (level >= map[dist].second) {
		// update value and level for the current distance
		map[dist] = { node->data, level };
	}
	solve(node->left, dist - 1, level + 1, map);
	solve(node->right, dist + 1, level + 1, map);
}

vector<int> bottomView(Node *root) {
	vector<int> ans;
	// `key` => relative horizontal distance of the node from the root node, and
	// `value` => pair containing the node's value and its level
	map<int, pair<int, int>> map;
	// perform preorder traversal on the tree and fill the map
	solve(root, 0, 0, map);
	// traverse the map and print the bottom view
	for (auto &p : map) {
		ans.push_back(p.second.first);
	}
	return ans;
}