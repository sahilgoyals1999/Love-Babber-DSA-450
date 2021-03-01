// https://www.geeksforgeeks.org/next-smaller-element/

// prints element and NSE pair for all elements of a[] of size n
vector<int> printNSE(int a[], int n) {
	stack<int> s;
	vector<int> ans(n, -1);
	// push the first element to stack
	s.push(a[0]);
	// iterate for rest of the elements
	for (int i = 1; i < n; ++i) {
		if (s.empty()) {
			s.push(a[i]);
			continue;
		}
		/* else => pop an element from stack. If it is greater than next, then
		a) print the pair
		b) keep popping while elements are greater and stack is not empty */
		while (!s.empty() && s.top() > a[i]) {
			ans[s.top()] = a[i];
			s.pop();
		}
		// push next to stack so that we can find next smaller for it
		s.push(a[i]);
	}
	return ans;
}