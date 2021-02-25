// https://www.geeksforgeeks.org/building-heap-from-array/

// T.C => O(n), S.C => O(1)

// To heapify a subtree rooted with node i which is an index in a[]. N is size of heap
void heapify(int a[], int n, int i) {
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	// If left child is larger than root
	if (l < n && a[l] > a[largest]) {
		largest = l;
	}
	// If right child is larger than largest so far
	if (r < n && a[r] > a[largest]) {
		largest = r;
	}
	// If largest is not root
	if (largest != i) {
		swap(a[i], a[largest]);
		// Recursively heapify the affected sub-tree
		heapify(a, n, largest);
	}
}

// Function to build a Max-Heap from the given array
void buildHeap(int a[], int n) {
	// Index of last non-leaf node
	int startIdx = (n / 2) - 1;
	// Perform reverse level order traversal from last non-leaf node and heapify each node
	for (int i = startIdx; i >= 0; --i) {
		heapify(a, n, i);
	}
}