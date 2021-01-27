// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0

// T.C => O(n*log(n) + m*log(m)), S.C => O(1)
// Sorting and Merging

#include        <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

int main() {
	FIO
	w(t) {
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int j = 0; j < m; ++j) {
			cin >> b[j];
		}
		sort(a, a + n);
		sort(b, b + m);
		int i = 0, j = 0;
		while (i < n && j < m) {
			// If the element is smaller than move aheaad in the first array
			if (a[i] < b[j]) i++;
			// If both are equal, then move both of them forward
			else if (a[i] == b[j]) {
				i++;
				j++;
			}
			// If we donot have a element smaller or equal to the second array then break
			else break;
		}
		if (j < m) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}