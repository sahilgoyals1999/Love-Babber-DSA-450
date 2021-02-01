// https://www.geeksforgeeks.org/print-subsequences-string/

void printSubSeqRec(string s, int n, int index = -1, string curr = "") {
	// base case
	if (index == n) return;
	if (!curr.empty()) {
		cout << curr << "\n";
	}
	for (int i = index + 1; i < n; ++i) {
		curr += str[i];
		printSubSeqRec(str, n, i, curr);
		// backtracking
		curr = curr.erase(curr.size() - 1);
	}
	return;
}