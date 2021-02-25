// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// T.C => O(n^2), S.C => O(1)

bool comp(Job a, Job b) {
	return a.profit > b.profit;
}

pair<int, int> JobScheduling(Job a[], int n) {
	sort(a, a + n, comp);
	int mx = a[0].dead;
	for (int i = 1; i < n; ++i) {
		mx = max(mx, a[i].dead);
	}
	int slot[mx + 1];
	for (int i = 0; i <= mx; ++i) {
		slot[i] = -1;
	}
	int countJobs = 0, jobProfit = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = a[i].dead; j > 0; --j) {
			if (slot[j] == -1) {
				slot[j] = i;
				countJobs++;
				jobProfit += a[i].profit;
				break;
			}
		}
	}
	return make_pair(countJobs, jobProfit);
}