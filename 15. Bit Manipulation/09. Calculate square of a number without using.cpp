// https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/

// T.C => O(log(n)), S.C => O(1)

int square(int n) {
	// Base case
	if (n == 0) return 0;
	// Handle negative number
	if (n < 0) n = -n;
	// Get floor(n/2) using right shift
	int x = n >> 1;
	// If n is odd
	if (n & 1) return ((square(x) << 2) + (x << 2) + 1);
	// If n is even
	return (square(x) << 2);
}