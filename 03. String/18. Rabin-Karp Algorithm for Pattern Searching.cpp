// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

// T.C => for Avg. Case O(n + m), for Worst Case O(n*m)
// Assume n > m

#include        <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

#define d 256

void search(string txt, string pat, int q)  {
	int n = txt.length();
	int m = pat.length();
	int p = 0; // hash value for pattern
	int t = 0; // hash value for text
	int h = 1;
	// h = pow(d, m-1)%q
	for (int i = 0; i < m - 1; ++i) {
		h = (h * d) % q;
	}
	// Calculate the hash value of pattern and first window of text
	for (int i = 0; i < m; ++i) {
		p = (p * d + pat[i]) % q;
		t = (t * d + txt[i]) % q;
	}
	// Slide the pattern over text one by one
	for (int i = 0; i <= n - m; ++i) {
		// Check the hash values of current window of text and pattern.
		// If the hash values match
		if (p == t) {
			// Check for characters one by one
			int j = 0;
			while (j < m) {
				if (txt[i + j] != pat[j]) break;
				++j;
			}
			// if p == t and pat[0...m-1] = txt[i, i+1, ...i+m-1]
			if (j == m) cout << i << "\n";
		}
		// Calculate hash value for next window of text: Remove leading digit, add trailing digit
		if (i < n - m) {
			t = (d * (t - txt[i] * h) + txt[i + m]) % q;
			// We might get negative value of t, converting it to positive
			if (t < 0) t += q;
		}
	}
}

int main() {
	FIO
	string txt, pat;
	cin >> txt >> pat;
	int q = 101; // Prime Number
	search(txt, pat, q);
	return 0;
}