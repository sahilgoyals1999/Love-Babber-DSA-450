// https://practice.geeksforgeeks.org/problems/phone-directory/0#

#include        <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;

// trie node
class TrieNode {
public:
	TrieNode **children;
	bool is_terminal;

	TrieNode() {
		children = new TrieNode*[26];
		for (int i = 0; i < 26; ++i) {
			children[i] = NULL;
		}
		is_terminal = false;
	}

	~TrieNode() {
		for (int i = 0; i < 26; ++i) {
			delete children[i];
		}
	}
};

// Inserts a word into the trie
void insert(string s, TrieNode *root) {
	TrieNode *temp = root;
	for (int i = 0; i < s.length(); ++i) {
		int idx = s[i] - 'a';
		if (!temp->children[idx]) {
			temp->children[idx] = new TrieNode();
		}
		temp = temp->children[idx];
	}
	temp->is_terminal = true;
}

void printAll(TrieNode* root, string s, bool &c) {
	if (!root) return;
	else if (root->is_terminal) {
		c = true;
		cout << s << " ";
	}
	for (int i = 0; i < 26; ++i) {
		printAll(root->children[i], s + (char)('a' + i), c);
	}
}

void print(TrieNode* root, string s, bool &c) {
	TrieNode* temp = root;
	for (int i = 0; i < s.length(); ++i) {
		int idx = s[i] - 'a';
		if (temp->children[idx] == NULL) {
			return;
		}
		temp = temp->children[idx];
	}
	printAll(temp, s, c);
}

int main() {
	FIO
	w(t) {
		int n;
		cin >> n;
		TrieNode* root = new TrieNode();
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			insert(s, root);
		}
		string p, q;
		cin >> p;
		for (int i = 0; i < p.length(); ++i) {
			q += p[i];
			bool c = false;
			print(root, q, c);
			if (!c) cout << "0";
			cout << "\n";
		}
	}
	return 0;
}





