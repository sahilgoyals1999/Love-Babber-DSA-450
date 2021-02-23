// https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

// T.C => O(1), S.C => O(1)

int isPowerOfTwo(unsigned n) {
	return n && (!(n & (n - 1)));
}

int findPosition(int n) {
	if (!isPowerOfTwo(n)) return -1;
	return log2(n) + 1;
}