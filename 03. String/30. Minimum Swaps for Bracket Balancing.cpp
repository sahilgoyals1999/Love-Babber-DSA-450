// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing/0

// T.C => O(n), S.C => O(1)

long swapCount(string s) {
	int n = s.length();
	// Stores total number of Left and Right brackets encountered
	int countLeft = 0, countRight = 0;
	// ans => number of swaps required
	// imbalance => number of imbalance pair
	int ans = 0, imbalance = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '[') {
			countLeft++;
			if (imbalance > 0) {
				ans += imbalance;
				// imbalance decremented by 1 as it solved only one imbalance of Left and Right
				imbalance--;
			}
		}
		else {
			countRight++;
			// imbalance is reset to current difference between Left and Right brackets
			imbalance = (countRight - countLeft);
		}
	}
	return ans;
}