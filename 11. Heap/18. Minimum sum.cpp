// https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#

// T.C => O(n), S.C => O(1)

string findSum(string x, string y) {
	int i = x.length() - 1, j = y.length() - 1;
	string ans = "";
	int c = 0;
	while (i >= 0 && j >= 0) {
		int d1 = x[i] - '0';
		int d2 = y[j] - '0';
		int sum = (d1 + d2 + c) % 10;
		c = (d1 + d2 + c) / 10;
		ans = to_string(sum) + ans;
		--i;
		--j;
	}
	while (i >= 0) {
		int d1 = x[i] - '0';
		int sum = (d1 + c) % 10;
		c = (d1 + c) / 10;
		ans = to_string(sum) + ans;
		--i;
	}
	while (j >= 0) {
		int d2 = y[j] - '0';
		int sum = (d2 + c) % 10;
		c = (d2 + c) / 10;
		ans = to_string(sum) + ans;
		--j;
	}
	if (c > 0) {
		ans = to_string(c) + ans;
	}
	for (int i = 0; i < ans.length(); ++i) {
		if (ans[i] != '0') {
			return ans.substr(i);
		}
	}
	return "0";
}

string solve(int a[], int n) {
	// sort the array
	sort(a, a + n);
	// let two numbers be x and y
	string x, y;
	for (int i = 0; i < n; ++i) {
		// fill a and b with every alternate digit of input array
		if (i & 1) x += to_string(a[i]);
		else y += to_string(a[i]);
	}
	// return the sum
	return findSum(x, y);
}