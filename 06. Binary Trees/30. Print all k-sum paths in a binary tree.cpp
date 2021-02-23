// https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/

// T.C => O(), S.C => O()

void printVector(const vector<int>& v, int i) {
	for (int j = i; j < v.size(); ++j) {
		cout << v[j] << " ";
	}
	cout << "\n";
}

// This function prints all paths that have sum k
void solve(Node *root, vector<int> &path, int k) {
	if (!root) return;
	// add current node to the path
	path.push_back(root->data);
	// check if there's any k sum path in the left sub-tree.
	solve(root->left, path, k);
	// check if there's any k sum path in the right sub-tree.
	solve(root->right, path, k);
	// check if there's any k sum path that terminates at this node
	// Traverse the entire path as there can be negative elements too
	int sum = 0;
	for (int j = path.size() - 1; j >= 0; --j) {
		sum += path[j];
		// If path sum is k, print the path
		if (sum == k) printVector(path, j);
	}
	// Remove the current element from the path => Backtracking
	path.pop_back();
}

// A wrapper over printKPathUtil()
void printKPath(Node *root, int k) {
	vector<int> path;
	solve(root, path, k);
}