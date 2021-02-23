// https://practice.geeksforgeeks.org/problems/set-bits0143/1

// T.C => O(log(x)), S.C => O(1)

int setBits(int x) {
	int ans = 0;
	while (x > 0) {
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}