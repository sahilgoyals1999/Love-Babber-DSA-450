// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

// T.C => O(n), S.C => O(n)

int evaluatePostfix(string str) {
	int n = str.length();
	stack<int> s;
	for (int i = 0; i < n; ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			s.push(str[i] - '0');
		}
		else {
			int n1 = s.top();
			s.pop();
			int n2 = s.top();
			s.pop();
			if (str[i] == '*') {
				s.push(n1 * n2);
			}
			else if (str[i] == '/') {
				s.push(n2 / n1);
			}
			else if (str[i] == '+') {
				s.push(n1 + n2);
			}
			else if (str[i] == '-') {
				s.push(n2 - n1);
			}
		}
	}
	return s.top();
}