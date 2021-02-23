// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

// T.C => O(log(n)), S.C => O(1)

unsigned int countSetBits(unsigned int n) {
	n++;
	unsigned int ans = 0, i = 2;
	//counting set bits from 1 to n
	while (i / 2 < n) {
		int quo = n / i;
		int rem = n % i;
		ans += ((quo * i) / 2);
		if (rem > i / 2) ans += (rem - i / 2);
		i *= 2;
	}
	return ans;
}