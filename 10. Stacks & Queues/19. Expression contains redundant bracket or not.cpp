// https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/

// T.C => O(n), S.C => O(n)

// Function to check redundant brackets in a balanced expression
bool checkRedundancy(string &s) {
	// create a stack of characters
	stack<char> st;
	// Iterate through the given expression
	for (auto &c : s) {
		// if current character is close parenthesis ')'
		if (c == ')') {
			char tp = st.top();
			st.pop();
			// If immediate pop have open parenthesis '(' duplicate brackets found
			bool flag = true;
			while (tp != '(') {
				// Check for operators in expression
				if (tp == '+' || tp == '-' || tp == '*' || tp == '/') {
					flag = false;
				}
				// Fetch top element of stack
				tp = st.top();
				st.pop();
			}
			// If operators not found
			if (flag == true) return true;
		}
		else {
			st.push(c); // push open parenthesis '(', operators and operands to stack
		}
	}
	return false;
}