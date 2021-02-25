// https://practice.geeksforgeeks.org/problems/water-connection-problem/0

// T.C => O(n), S.C => O(n)

#include        <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

pair<int, int> dfs(vector<pair<int, int>> g[], int u, int w) {
	pair<int, int> p = { u, w };
	for (auto &i : g[u]) {
		p = dfs(g, i.first, i.second);
	}
	p.second = min(p.second , w);
	return p;
}

int main() {
	FIO
	w(t) {
		int n, p;
		cin >> n >> p;
		vector<pair<int, int>> g[n];
		int indegree[n] = {};
		for (int i = 0; i < p; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			u--;
			v--;
			g[u].push_back({ v, w });
			indegree[v]++;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!indegree[i] && g[i].size() != 0) ans++;
		}
		cout << ans << "\n";
		for (int i = 0; i < n; ++i) {
			if (!indegree[i] && g[i].size() != 0) {
				pair<int, int> p = dfs(g, i, INT_MAX);
				cout << i + 1 << " " << p.first + 1 << " " << p.second << "\n";
			}
		}
	}
	return 0;
}