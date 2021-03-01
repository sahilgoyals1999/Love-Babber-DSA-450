// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

// T.C => O(n), S.C => O(n)

// Returns sum of min and max element of all subarrays of size k
int SumOfKsubArray(int a[] , int n , int k) {
	int sum = 0;
	// The queue will store indexes of useful elements in every window
	// In deque 'G' we maintain decreasing order of values from front to rear
	// In deque 'S' we  maintain increasing order of values from front to rear
	deque<int> S(k), G(k);
	// Process first window of size k
	for (int i = 0; i < k; ++i) {
		// Remove all previous greater elements that are useless.
		while (!S.empty() && a[S.back()] >= a[i]) {
			S.pop_back(); // Remove from rear
		}
		// Remove all previous smaller that are elements are useless.
		while (!G.empty() && a[G.back()] <= a[i]) {
			G.pop_back(); // Remove from rear
		}
		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}
	// Process rest of the Array elements
	for (int i = k; i < n; ++i) {
		// Element at the front of the deque 'G' & 'S' is the largest and smallest
		// element of previous window respectively
		sum += a[S.front()] + a[G.front()];
		// Remove all elements which are out of this window
		while (!S.empty() && S.front() <= i - k) {
			S.pop_front();
		}
		while (!G.empty() && G.front() <= i - k) {
			G.pop_front();
		}
		// remove all previous greater element that are useless
		while (!S.empty() && a[S.back()] >= a[i]) {
			S.pop_back(); // Remove from rear
		}
		// remove all previous smaller that are elements are useless
		while (!G.empty() && a[G.back()] <= a[i]) {
			G.pop_back(); // Remove from rear
		}
		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}
	// Sum of minimum and maximum element of last window
	sum += a[S.front()] + a[G.front()];
	return sum;
}