// https://practice.geeksforgeeks.org/problems/max-rectangle/1

// T.C => O(R*C), S.C => O(C)

int maxHist(int row[], int C) {
	// Create a stack it holds indexes of hist[] array/ The bars stored
	// in stack are always in increasing order of their heights.
	stack<int> s;
	int mx = 0;
	// row (or histogram)
	int area = 0;
	// Run through all bars of given histogram (or row)
	int i = 0;
	while (i < C) {
		// If this bar is higher than the bar on top stack, push it to stack
		if (s.empty() || row[s.top()] <= row[i]) s.push(i++);
		else {
			// else, calculate area of rectangle with stack top as
			// the smallest (or minimum height) bar. 'i' is
			// 'right index' for the top and element before
			// top in stack is 'left index'
			int tp = row[s.top()];
			s.pop();
			area = tp * i;
			if (!s.empty()) area = tp * (i - s.top() - 1);
			mx = max(area, mx);
		}
	}
	// Now pop the remaining bars from stack and calculate
	// area with every popped bar as the smallest bar
	while (!s.empty()) {
		int tp = row[s.top()];
		s.pop();
		area = tp * i;
		if (!s.empty()) area = tp * (i - s.top() - 1);
		mx = max(area, mx);
	}
	return mx;
}

int maxArea(int A[MAX][MAX], int R, int C) {
	// Calculate area for first row and initialize it as ans
	int ans = maxHist(A[0], C);
	// iterate over row to find maximum rectangular are considering each row as histogram
	for (int i = 1; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			// if A[i][j] is 1 then add A[i -1][j]
			if (A[i][j] == 1) A[i][j] += A[i - 1][j];
		}
		// Update result if area with current row (as last row) of rectangle) is more
		ans = max(ans, maxHist(A[i], C));
	}
	return ans;
}