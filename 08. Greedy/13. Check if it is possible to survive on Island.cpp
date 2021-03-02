// https://www.geeksforgeeks.org/survival/

// T.C => O(1), S.C => O(1)

// function to find the minimum days
int survival(int S, int N, int M) {
	// If we can not buy at least a week supply of food during the first week
	// OR
	// We can not buy a day supply of food on the first day then we can't survive.
	if (((N * 6) < (M * 7) && S > 6) || N < M) {
		return -1;
	}
	else {
		// If we can survive then we can buy ceil(A/N) times
		// where A is total units of food required.
		int A = M * S;
		int days = ceil((A * 1.0) / N);
		return days;
	}
}