// https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/

// T.C => O(m), S.C => O(m)

// returns vector lps for given string str
vector<int> computeLPSArray(string s) {
	int m = s.length();
	vector<int> lps(m);
	int len = 0;
	lps[0] = 0; // lps[0] is always 0
	// the loop calculates lps[i] for i = 1 to m-1
	int i = 1;
	while (i < m) {
		if (s[i] == s[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar to search step.
			if (len != 0) {
				len = lps[len - 1];
				// Also, note that we do not increment i here
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

// Method returns minimum character to be added at front to make string palindrome
int getMinCharToAddedToMakeStringPalin(string s) {
	string revS = s;
	reverse(revS.begin(), revS.end());
	// Get concatenation of string, special character and reverse string
	string concat = s + "$" + revS;
	// Get LPS array of this concatenated string
	vector<int> lps = computeLPSArray(concat);
	// By subtracting last entry of lps vector from string length, we will get our result
	return (s.length() - lps.back());
}