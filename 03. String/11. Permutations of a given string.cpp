// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include        <bits/stdc++.h>
#define FAST    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

vector<string> ans;

void permutaions(string s, int l, int r) {
	// Base Case
	if (l == r) {
		ans.push_back(s);
		return;
	}
	for (int i = l ; i <= r; ++i) {
		swap(s[l], s[i]);
		permutaions(s, l + 1 , r);
		swap(s[l], s[i]);          // Backtracking
	}
}

int main() {
	FAST
	w(t) {
		ans.clear();
		string s;
		cin >> s;
		int l = 0, r = s.length() - 1;
		permutaions(s, 0 , r);
		sort(ans.begin(), ans.end());
		for (string &x : ans) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}