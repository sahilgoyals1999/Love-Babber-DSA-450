// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0#

// T.C => O(n), S.C => O(n)

#include        <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

int main() {
	FIO
	w(t) {
		int n, k;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cin >> k;
		deque<int> q;
		// push all -ve elements from 1 to k
		for (int i = 0; i < k; ++i) {
			if (a[i] < 0) {
				q.push_back(i);
			}
		}
		for (int i = k; i < n; ++i) {
			if (!q.empty()) cout << a[q.front()] << " ";
			else cout << "0 ";
			// remove out of range elements
			while (!q.empty() && q.front() <= i - k) {
				q.pop_front();
			}
			if (a[i] < 0) q.push_back(i);
		}
		if (!q.empty()) cout << a[q.front()] << "\n";
		else cout << "0\n";
	}
	return 0;
}