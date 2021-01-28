// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

// maximum value of (A(c,d) - A(a,b)) such that c > a, d > b.
// T.C => O(n^2), S.C => O(n^2)

#define N 5

int findMaxValue(int A[][N]) {
	// dp[i][j] => max of elements in matrix from (i, j) to (N-1, N-1)
	int dp[N][N];
	// last element of dp will be same as of the input matrix
	dp[N - 1][N - 1] = A[N - 1][N - 1];
	// last row
	int mx = A[N - 1][N - 1];
	for (int j = N - 2; j >= 0; --j) {
		mx = max(mx, A[N - 1][j]);
		dp[N - 1][j] = mx;
	}
	// last column
	mx = A[N - 1][N - 1];
	for (int i = N - 2; i >= 0; --i) {
		mx = max(mx, A[i][N - 1]);
		dp[i][N - 1] = mx;
	}
	int ans = INT_MIN;
	for (int i = N - 2; i >= 0; --i) {
		for (int j = N - 2; j >= 0; --j) {
			ans = max(ans, dp[i + 1][j + 1] - A[i][j]);
			dp[i][j] = max({ A[i][j], dp[i][j + 1], dp[i + 1][j] });
		}
	}
	return ans;
}