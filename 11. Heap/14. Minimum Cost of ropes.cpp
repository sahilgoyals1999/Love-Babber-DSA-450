// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// T.C => O(n*log(n)), S.C => O(n)

long long minCost(long long a[], long long n) {
	long long ans = 0;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; ++i) {
		pq.push(a[i]);
	}
	while (pq.size() > 1) {
		long long x = pq.top();
		pq.pop();
		long long y = pq.top();
		pq.pop();
		ans += (x + y);
		pq.push(x + y);
	}
	return ans;
}
