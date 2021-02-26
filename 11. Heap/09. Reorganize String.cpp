// https://leetcode.com/problems/reorganize-string/

// T.C => O(n), S.C => O(1)

string reorganizeString(string s) {
	vector<int> count(26, 0);
	int mx = 0, i = 0;
	for (char &c : s) {
		count[c - 'a']++;
		if (count[c - 'a'] > count[mx]) {
			mx = (c - 'a');
		}
	}
	if (2 * count[mx] - 1 > s.length()) return "";
	while (count[mx]) {
		s[i] = (mx + 'a');
		i += 2;
		count[mx]--;
	}
	for (int j = 0; j < 26; ++j) {
		while (count[j]) {
			if (i >= s.length()) i = 1;
			s[i] = (j + 'a');
			count[j]--;
			i += 2;
		}
	}
	return s;
}