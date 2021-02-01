// https://leetcode.com/problems/count-and-say/

string countAndSay(int n) {
	if (n == 0) return "";
	string ans = "1";
	while (n > 1) {
		string cur = "";
		int l = ans.length();
		for (int i = 0; i < l; ++i) {
			int count = 1;
			while (i + 1 < l && (ans[i] == ans[i + 1])) {
				count++;
				i++;
			}
			cur += to_string(count) + ans[i];
		}
		ans = cur;
		--n;
	}
	return ans;
}