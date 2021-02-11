// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0#

// T.C => O(2*log(n)), S.C => O(1)

#include        <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

int main() {
	FIO
	w(t) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		// for first location
		int f = lower_bound(a, a + n, x) - a;
		if (f < n && a[f] == x) cout << f << " ";
		else cout << "-1\n";
		// for last location
		int l = upper_bound(a, a + n, x) - a;
		l--;
		if (l >= 0 && a[l] == x) cout << l << "\n";
	}
	return 0;
}