// https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

// T.C => O(n), S.C => O(1)

#include <bits/stdc++.h>
using namespace std;

// Function which computes the sequence
string printSequence(string str[], string s) {
	string ans = "";
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		if (s[i] == ' ') ans += "0";
		else {
			// Calculating index for each character
			int pos = s[i] - 'A';
			ans += str[pos];
		}
	}
	return ans;
}

int main() {
	// storing the sequence in array
	string str[] = {"2", "22", "222",
	                "3", "33", "333",
	                "4", "44", "444",
	                "5", "55", "555",
	                "6", "66", "666",
	                "7", "77", "777", "7777",
	                "8", "88", "888",
	                "9", "99", "999", "9999"
	               };
	string s;
	cin >> s;
	cout << printSequence(str, s);
	return 0;
}