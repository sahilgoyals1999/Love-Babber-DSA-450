// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

// T.C => O(log(max(a,b))), S.C => O(1)

int countBitsFlip(int a, int b) {
	int x = a ^ b, ans = 0;
	while (x > 0) {
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}