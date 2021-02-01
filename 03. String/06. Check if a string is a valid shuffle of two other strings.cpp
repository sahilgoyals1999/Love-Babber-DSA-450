// https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings

// T.C => O(l3), S.C => O(1)

bool shuffleCheck(string s, string t, string ans) {
	int l1 = s.length(), l2 = t.length(), l3 = ans.length();
	// check length of result is same as sum of result of first and second
	if (l1 + l2 != l3) return false;
	// variables to track each character of 3 strings
	int i = 0, j = 0, k = 0;
	// iterate through all characters of result
	while (k != l3) {
		// if first character of ans matches with first character of first string
		if (i < l1 && s[i] == ans[k]) i++;
		// if first character of ans matches the first character of second string
		else if (j < l2 && t[j] == ans[k]) j++;
		// if the character doesn't match
		else return false;
		k++;
	}
	// after accessing all characters of result if either first or second has some characters left
	if (i < l1 || j < l2) return false;
	return true;
}