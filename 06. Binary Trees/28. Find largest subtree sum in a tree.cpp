// https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/

// T.C => O(n), S.C => O(n)

// Helper function to find largest subtree sum recursively.
int solve(Node* root, int& ans) {
	if (!root) return 0;
	// Subtree sum rooted at current node.
	int currSum = root->key + solve(root->left, ans) + solve(root->right, ans);
	// Update answer if current subtree sum is greater than answer so far.
	ans = max(ans, currSum);
	return currSum;
}

// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root) {
	// If tree does not exist, then answer is 0.
	if (!root) return 0;
	// Variable to store maximum subtree sum.
	int ans = INT_MIN;
	// Call to recursive function to find maximum subtree sum.
	solve(root, ans);
	return ans;
}