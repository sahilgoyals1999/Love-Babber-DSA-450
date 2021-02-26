// https://www.geeksforgeeks.org/convert-min-heap-to-max-heap/

// T.C => O(n), S.C => O(1)

// to heapify a subtree with root at given index
void MaxHeapify(int a[], int i, int n) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && a[l] > a[i]) {
		largest = l;
	}
	if (r < n && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(a[i], a[largest]);
		MaxHeapify(a, largest, n);
	}
}

// function to builds max heap
void convertMaxHeap(int a[], int n) {
	// Start from bottommost and rightmost
	// internal mode and heapify all internal
	// modes in bottom up way
	for (int i = (n - 2) / 2; i >= 0; --i) {
		MaxHeapify(a, i, n);
	}
}