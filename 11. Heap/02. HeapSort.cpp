// https://www.geeksforgeeks.org/heap-sort/

// T.C => O(n*log(n)), S.C => O(1)

// To heapify a subtree rooted with node i which is n index in a[]. n is size of heap
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

// function to do heap sort
void heapSort(int a[], int n) {
	// Build heap (rearrange array)
	int startIndex = n / 2 - 1;
	for (int i = startIndex; i >= 0; --i) {
		heapify(a, n, i);
	}
	// One by one extract an element from heap
	for (int i = n - 1; i > 0; --i) {
		// Move current root to end
		swap(a[0], a[i]);
		// call max heapify on the reduced heap
		heapify(a, i, 0);
	}
}