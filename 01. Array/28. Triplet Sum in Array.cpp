// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// T.C => O(n^2), S.C => O(1)

bool find3Numbers(int a[], int n, int x) {
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int target = x - a[i];
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = a[left] + a[right];
            if (sum == target) return true;
            if (sum > target) --right;
            else ++left;
        }
    }
    return false;
}