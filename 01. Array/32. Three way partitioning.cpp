// https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#

// T.C => O(n), S.C => O(1)

void threeWayPartition(vector<int>& a, int x, int y) {
	int left = 0, right = a.size() - 1, i = 0;
	while (i <= right) {
		if (a[i] < x) {
			swap(a[i], a[left]);
			++left;
			++i;
		}
		else if (a[i] > y) {
			swap(a[i], a[right]);
			--right;
		}
		else ++i;
	}
}