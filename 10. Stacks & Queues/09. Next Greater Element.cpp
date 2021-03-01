// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// T.C => O(n), S.C => O(n)

vector<long long> nextLargerElement(vector<long long> a, int n) {
	stack<long long> s;
	vector<long long> ans(n);
	// iterating from n-1 to 0
	for (int i = n - 1; i >= 0; --i) {
		// We will pop till we get the greater element on top or stack gets empty
		// remove useless elements
		while (!s.empty() && s.top() <= a[i]) {
			s.pop();
		}
		// if stack is empty => no element on right which is greater than the current element
		// else => the next greater lement is on top of stack
		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();
		s.push(a[i]);
	}
	return ans;
}