// https://practice.geeksforgeeks.org/problems/smallest-number5829/1

// T.C => O(d), S.C => O(1)

string smallestNumber(int s, int d) {
	if (d * 9 < s) {
		return "-1";
	}
	string ans;
	--s;
	--d;
	while (d > 0) {
		if (s >= 9) {
			ans = '9' + ans;
			s -= 9;
		}
		else {
			ans = to_string(s) + ans;
			s = 0;
		}
		--d;
	}
	if (s > 0) {
		ans = to_string(s + 1) + ans;
	}
	else {
		ans = '1' + ans;
	}
	return ans;
}