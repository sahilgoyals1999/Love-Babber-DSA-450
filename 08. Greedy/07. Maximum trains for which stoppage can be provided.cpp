// https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/

// number of platforms and trains
#define n 2
#define m 5

// function to calculate maximum trains stoppage
int maxStop(int arr[][3]) {
	// declaring vector of pairs for platform
	vector<pair<int, int>> v[n + 1];
	// Entering values in vector of pairs as per platform number
	// make departure time first element of pair
	for (int i = 0; i < m; ++i) {
		v[arr[i][2]].push_back(make_pair(arr[i][1], arr[i][0]));
	}
	// sort trains for each platform as per dept. time
	for (int i = 0; i <= n; ++i) {
		sort(v[i].begin(), v[i].end());
	}
	// perform activity selection approach
	int count = 0;
	for (int i = 0; i <= n; ++i) {
		if (v[i].size() == 0) continue;
		// first train for each platform will also be selected
		int x = 0;
		count++;
		for (int j = 1; j < v[i].size(); ++j) {
			if (v[i][j].second >= v[i][x].first) {
				x = j;
				count++;
			}
		}
	}
	return count;
}