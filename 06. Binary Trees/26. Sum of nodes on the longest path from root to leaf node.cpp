// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#

// T.C => O(n), S.C => O(1)

void solve(Node *root, int height, int sum, int &maxHeight, int &maxSum) {
	if (!root) return;
	sum += root->data;
	if (!root->left && !root->right && height >= maxHeight) {
		maxHeight = height;
		maxSum = max(maxSum, sum);
	}
	solve(root->left, height + 1, sum, maxHeight, maxSum);
	solve(root->right, height + 1, sum, maxHeight, maxSum);
}

int sumOfLongRootToLeafPath(Node* root) {
	int height = 0, maxHeight = 0;
	int sum = 0, maxSum = 0;
	solve(root, height, sum, maxHeight, maxSum);
	return maxSum;
}