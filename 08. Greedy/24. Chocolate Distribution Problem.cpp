// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0

// T.C => O(n*log(n)), S.C => O(1)

#include        <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

int main() {
	FIO
	w(t) {
		int n, m;
		cin >> n;
		long long a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cin >> m;
		sort(a, a + n);
		long long ans = INT_MAX;
		for (int i = 0; i <= n - m; ++i) {
			ans = min(ans, a[i + m - 1] - a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}