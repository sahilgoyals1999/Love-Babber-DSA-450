// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// T.C => O(n), S.C => O(n)
// Counting Sort

int kthSmallest(int a[], int l, int r, int k) {
    int count[100001] = {};
    for (int i = l; i <= r; ++i) {
        count[a[i]]++;
    }
    int i = 1;
    while (i < 100001) {
        k -= count[i];
        if (k <= 0) return i;
        ++i;
    }
    return -1;
}