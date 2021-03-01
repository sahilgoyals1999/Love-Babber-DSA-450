// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// T.C => O(26*n), S.C => O(26)

string FirstNonRepeating(string A) {
	int n = A.length();
	vector<int> f(26, 0);
	vector<int> last(26, -1);
	for (int i = 0; i < n; ++i) {
		if (last[A[i] - 'a'] == -1) {
			last[A[i] - 'a'] = i;
		}
	}
	string ans;
	for (int i = 0; i < n; ++i) {
		f[A[i] - 'a']++;
		char ch = '#';
		int x = n + 1;
		for (int j = 0; j < 26; ++j) {
			if (f[j] == 1 && x > last[j]) {
				ch = char(j + 'a');
				x = last[j];
			}
		}
		ans += ch;
	}
	return ans;
}