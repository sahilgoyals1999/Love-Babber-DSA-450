// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#

// T.C => O(1), S.C => O(1)
void StackQueue :: push(int x) {
	s1.push(x);
}

// T.C => O(n), S.C => O(1)
int StackQueue :: pop() {
	if (s2.empty()) {
		if (s1.empty()) return -1; // if both stacks are empty, we return -1
		while (!s1.empty()) {
			int r = s1.top();      // removing elements from s1
			s1.pop();              // and pushing into s2, this way,
			s2.push(r);            // order of elemets is reversed
		}
	}
	int k = s2.top();              // s2 hold elements in reversed order
	s2.pop();
	return k;
}