// https://practice.geeksforgeeks.org/problems/special-stack/1#

// T.C => O(1), S.C => O(1)

void push(stack<int>& s, int a) {
	if (s.empty()) {
		s.push(a);
		s.push(a);
		return;
	}
	if (a < s.top()) {
		s.push(a);
		s.push(a);
		return;
	}
	int min_value = s.top();
	s.push(a);
	s.push(min_value);
	return;
}

bool isFull(stack<int>& s, int n) {
	return s.size() >= 2 * n;
}

bool isEmpty(stack<int>& s) {
	return s.size() == 0;
}

int pop(stack<int>& s) {
	if (isEmpty(s)) return -1;
	s.pop();
	int x = s.top();
	s.pop();
	return x;
}

int getMin(stack<int>& s) {
	return s.top();
}