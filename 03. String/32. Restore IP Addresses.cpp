// https://leetcode.com/problems/restore-ip-addresses/

void dfs(string s, int start, int step, string ip, vector<string>& ans, int n) {
	if (start == n && step == 4) {
		ip.erase(ip.end() - 1); // remove the last '.' from the last decimal number
		ans.push_back(ip);
		return;
	}
	// checks whether it exceeds the amount of digits possible left for an IP address
	if (n - start > (4 - step) * 3) return;
	// checks whether we have enough digits left given the current progress
	if (n - start < (4 - step)) return;
	int num = 0;
	for (int i = start; i < start + 3; ++i) {
		num = num * 10 + (s[i] - '0');
		if (num <= 255) {
			ip += s[i];
			dfs(s, i + 1, step + 1, ip + '.', ans, n);
		}
		if (num == 0) break;
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> ans;
	string ip;
	int n = s.size();
	//dfs(string s, start index of s, step(from 0-3), sub, ans, n)
	dfs(s, 0, 0, ip, ans, n);
	return ans;
}