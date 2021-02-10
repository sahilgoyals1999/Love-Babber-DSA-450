// https://practice.geeksforgeeks.org/problems/count-the-reversals/0#

// T.C => O(n), S.C => O(n)

int countMinReversals(string s) {
	int len = s.length();
	// length of expression must be even to make
	if (len % 2 == 1) return -1;
	// After this loop, stack contains unbalanced part of expression, i.e. "}}..}{{..{"
	stack<char> ss;
	for (int i = 0; i < len; ++i) {
		if (!ss.empty() && s[i] == '}') {
			if (ss.top() == '{') ss.pop();
			else ss.push(s[i]);
		}
		else ss.push(s[i]);
	}
	// m => count of '}'
	// n => count of '{'
	// count opening brackets at the end of stack
	int n = 0;
	while (!ss.empty() && ss.top() == '{') {
		ss.pop();
		n++;
	}
	int m = ss.size();
	return ceil(m / 2.0) + ceil(n / 2.0);
}