// https://practice.geeksforgeeks.org/problems/shop-in-candy-store/0#

// T.C => O(n*log(n)), S.C => O(1)

#include        <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

int main() {
	FIO
	w(t) {
		int n, k, mn = 0, mx = 0;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n);
		int i = 0, j = n - 1;
		while (i <= j) {
			mn += a[i++];
			j -= k;
		}
		i = 0, j = n - 1;
		while (i <= j) {
			mx += a[j--];
			i += k;
		}
		cout << mn << " " << mx << "\n";
	}
	return 0;
}