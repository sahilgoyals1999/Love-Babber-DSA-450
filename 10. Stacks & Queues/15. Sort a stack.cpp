// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// T.C => O(n^2), S.C => O(1)

void sortedInsert(stack<int> &s, int temp) {
	// if it is the first element then or it greater than top element push it
	if (s.empty() || temp > s.top()) {
		s.push(temp);
	}
	else {
		// pop all element till we get element greater then top of stack
		int tp = s.top();
		s.pop();
		// insert it
		sortedInsert(s, temp);
		// then insert all poped elements
		s.push(tp);
	}
}

void SortedStack :: sort() {
	// if size is 0 or 1 => already sorted
	if (s.size() == 0 || s.size() == 1) return;
	// push all emement in function call stack
	int temp = s.top();
	s.pop();
	sort();
	// insert the bottom most element in the stack
	sortedInsert(s, temp);
}