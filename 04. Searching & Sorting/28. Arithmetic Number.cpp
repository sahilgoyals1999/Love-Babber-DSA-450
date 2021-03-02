// https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1#

// T.C => O(1), S.C => O(1)

int inSequence(long A, long B, long C) {
	if (C == 0) return A == B;
	// checks if the term is greater than or equal to 0;
	int n = (B - A + C) / C ;
	return (B - A + C) % C == 0 && n > 0 ;
}