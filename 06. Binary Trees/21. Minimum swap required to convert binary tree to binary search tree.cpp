// https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/

// T.C => O(n*log(n)), S.C => O(n)

// inorder traversal of BST is in increasing order of their value.
// So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array.
// The minimum number of swap required to get the array sorted will be the answer.

void inorder(int a[], vector<int> &v, int n, int index) {
    // if index is greater or equal to vector size
    if (index >= n) return;
    inorder(a, v, n, 2 * index + 1);
    // push elements in vector
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}

int minSwaps(vector<int> &v) {
    int n = v.size();
    vector<pair<int, int>> t(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        t[i].first = v[i];
        t[i].second = i;
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < n; ++i) {
        // second element is equal to i
        if (i == t[i].second) continue;
        else {
            // swaping of elements
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }
        // Second is not equal to i
        if (i != t[i].second) --i;
        ++ans;
    }
    return ans;
}