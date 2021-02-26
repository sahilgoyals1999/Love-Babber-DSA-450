// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

// Using Dequeue
// T.C => O(n), S.C => O(k)

void printKMax(int a[], int n, int k) {
	// The deque will store indexes of useful elements in every window and it will
	// maintain decreasing order of values from front to rear in q, i.e.,
	// a[q.front[]] to a[q.rear()] are sorted in decreasing order
	deque<int> q(k);
	// Process first k (or first window) elements of array
	int i;
	for (i = 0; i < k; ++i) {
		// For every element, the previous smaller or equal elements are useless so remove them from q
		while ((!q.empty()) && a[i] >= a[q.back()]) {
			// Remove from rear
			q.pop_back();
		}
		// Add new element at rear of queue
		q.push_back(i);
	}
	// Process rest of the elements, i.e., from a[k] to a[n-1]
	for (; i < n; ++i) {
		// The element at the front of the queue is the largest element of previous window, so print it
		cout << a[q.front()] << " ";
		// Remove the elements which are out of this window
		while ((!q.empty()) && q.front() <= i - k) {
			// Remove from front of queue
			q.pop_front();
		}
		// Remove all elements smaller than the currently being added element (remove useless elements)
		while ((!q.empty()) && a[i] >= a[q.back()]) {
			q.pop_back();
		}
		// Add current element at the rear of q
		q.push_back(i);
	}
	// Print the maximum element of last window
	cout << a[q.front()];
}