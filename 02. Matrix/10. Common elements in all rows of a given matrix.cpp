// https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

// T.C => O(n*m), S.C => O(m)
#define N 4
#define M 5

void printCommonElements(int A[N][M]) {
	unordered_map<int, int> mp;
	// initalize 1st row elements with value 1
	for (int j = 0; j < N; ++j) {
		mp[A[0][j]] = 1;
	}
	// traverse the matrix
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			// If element is present in the map and is not duplicated in current row.
			if (mp[A[i][j]] == i) {
				// we increment count of the element in map by 1
				mp[A[i][j]]++;
				// If this is last row
				if (i == N - 1) cout << A[i][j] << " ";
			}
		}
	}
}