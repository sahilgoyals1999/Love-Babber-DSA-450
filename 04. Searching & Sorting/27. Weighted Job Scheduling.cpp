// https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/

// T.C => O(n*log(n)), S.C => O()

// C++ program for weighted job scheduling using Dynamic Programming and Binary Search
#include <iostream>
#include <algorithm>
using namespace std;

// A job has start time, finish time and profit.
class Job {
public:
	int start;
	int finish;
	int profit;
};

// A utility function that is used for sorting events according to finish time
bool comp(Job s1, Job s2) {
	return (s1.finish < s2.finish);
}

// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current job.
// "index" is index of the current job. This function
// returns -1 if all jobs before index conflict with it.
int binarySearch(Job jobs[], int index) {
	// Initialize 'lo' and 'hi' for Binary Search
	int lo = 0, hi = index - 1;
	// Perform binary Search iteratively
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (jobs[mid].finish <= jobs[index].start) {
			if (jobs[mid + 1].finish <= jobs[index].start) {
				lo = mid + 1;
			}
			else {
				return mid;
			}
		}
		else {
			hi = mid - 1;
		}
	}
	return -1;
}

// function that returns the maximum possible profit from given array of jobs
int findMaxProfit(Job a[], int n) {
	// Sort jobs according to finish time
	sort(a, a + n, comp);
	// dp[i] => profit for jobs till a[i] (including a[i])
	int *dp = new int[n];
	dp[0] = a[0].profit;
	// Fill entries in dp[] using recursive property
	for (int i = 1; i < n; ++i) {
		// Find profit including the current job
		int inclProf = a[i].profit;
		int l = binarySearch(a, i);
		if (l != -1) {
			inclProf += dp[l];
		}
		// Store maximum of including and excluding
		dp[i] = max(inclProf, dp[i - 1]);
	}
	// Store result and free dynamic memory allocated for dp[]
	int ans = dp[n - 1];
	delete[] dp;
	return ans;
}