// https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/

// T.C => O(n^2*log(k)), S.C => O(n)

// function to calculate kth largest element in contiguous subarray sum
int kthLargestSum(int a[], int n, int k) {
	// array to store prefix sums
	int sum[n + 1];
	sum[0] = 0;
	sum[1] = a[0];
	for (int i = 2; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i - 1];
	}
	// Min-Heap
	priority_queue<int, vector<int>, greater<int>> pq;
	// loop to calculate the contigous subarray sum position-wise
	for (int i = 1; i <= n; ++i) {
		// loop to traverse all positions that form contiguous subarray
		for (int j = i; j <= n; ++j) {
			// calculates the contiguous subarray sum from j to i index
			int x = sum[j] - sum[i - 1];
			// if queue has less then k elements, then simply push it
			if (pq.size() < k) {
				pq.push(x);
			}
			else if (pq.top() < x) {
				pq.pop();
				pq.push(x);
			}
		}
	}
	// the top element will be then kth largest element
	return pq.top();
}
