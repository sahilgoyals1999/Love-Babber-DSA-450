// https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

// T.C => O(n*sqrt(n)), S.C => O(1)

/* Let size of row and column be 3.
During first iteration –
a[i][j] = Element at first index (leftmost corner top)= 1.
a[j][n-1-i]= Rightmost corner top Element = 3.
a[n-1-i][n-1-j] = Righmost corner bottom element = 9.
a[n-1-j][i] = Leftmost corner bottom element = 7.
Move these elements in the clockwise direction.
During second iteration –
a[i][j] = 2.
a[j][n-1-j] = 6.
a[n-1-i][n-1-j] = 8.
a[n-1-j][i] = 4.
Similarly, move these elements in the clockwise direction. */

#define N 4

void rotate90Clockwise(int a[N][N]) {
	// Traverse each cycle
	for (int i = 0; i < N / 2; ++i) {
		for (int j = i; j < N - i - 1; ++j) {
			// Swap elements of each cycle in clockwise direction
			int temp = a[i][j];
			a[i][j] = a[N - 1 - j][i];
			a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
			a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
			a[j][N - 1 - i] = temp;
		}
	}
}