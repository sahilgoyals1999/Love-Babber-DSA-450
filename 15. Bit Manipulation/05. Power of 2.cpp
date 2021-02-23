// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1

// T.C => O(1), S.C => O(1)

bool isPowerofTwo(long long n) {
	return (n && !(n & (n - 1)));
}