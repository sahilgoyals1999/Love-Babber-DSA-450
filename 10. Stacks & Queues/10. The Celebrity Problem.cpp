// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

// T.C => O(n), S.C => O(n)

int celebrity(vector<vector<int>> &M, int n) {
	stack<int> s;
	for (int i = 0; i < n; ++i) {
		s.push(i);
	}
	while (s.size() > 1) {
		int guest1 = s.top();
		s.pop();
		int guest2 = s.top();
		s.pop();
		if (M[guest1][guest2] == 1 && M[guest2][guest1] == 0) {
			s.push(guest2);
		}
		else if (M[guest2][guest1] == 1 and M[guest1][guest2] == 0) {
			s.push(guest1);
		}
	}
	if (s.empty()) return -1;
	int candidate = s.top();
	for (int i = 0; i < n; ++i) {
		if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
			return -1;
		}
	}
	return candidate;
}