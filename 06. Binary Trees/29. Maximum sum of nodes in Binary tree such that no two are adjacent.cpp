// https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/

// T.C => O(n), S.C => O(1)

// first => maximum sum when the data of a node is included and
// second => maximum sum when the data of a particular node is not included.

pair<int, int> solve(Node *root) {
	if (!root) {
		pair<int, int> sum(0, 0);
		return sum;
	}
	pair<int, int> sum1 = solve(root->left);
	pair<int, int> sum2 = solve(root->right);
	pair<int, int> sum;
	// This node is included (Left and right children are not included)
	sum.first = sum1.second + sum2.second + root->data;
	// This node is excluded (Either left or right child is included)
	sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);
	return sum;
}

int maxSum(Node *root) {
	pair<int, int> res = maxSumHelper(root);
	return max(res.first, res.second);
}