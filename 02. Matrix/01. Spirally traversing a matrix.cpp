// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

// T.C => O(n^2), S.C => O(1)

vector<int> spirallyTraverse(vector<vector<int> > matrix, int n, int m) {
	vector<int> ans(n * m);
	int rowStart = 0;
	int rowEnd = n - 1;
	int colStart = 0;
	int colEnd = m - 1;
	int count = 0;
	while (rowStart <= rowEnd && colStart <= colEnd) {
		// left to right
		for (int i = colStart; i <= colEnd; ++i) {
			ans[count++] = matrix[rowStart][i];
		}
		rowStart++;
		// up to down
		for (int i = rowStart; i <= rowEnd; ++i) {
			ans[count++] = matrix[i][colEnd];
		}
		colEnd--;
		// right to left
		for (int i = colEnd; i >= colStart && rowStart <= rowEnd; --i) {
			ans[count++] = matrix[rowEnd][i];
		}
		rowEnd--;
		// down to up
		for (int i = rowEnd; i >= rowStart && colStart <= colEnd; --i) {
			ans[count++] = matrix[i][colStart];
		}
		colStart++;
	}
	return ans;
}