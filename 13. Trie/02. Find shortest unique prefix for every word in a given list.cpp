// https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/

#include<bits/stdc++.h>
using namespace std;
#define MAX 256

// Trie Node.
class TrieNode {
public:
	TrieNode **children;
	int freq;

	TrieNode() {
		children = new TrieNode*[MAX];
		for (int i = 0; i < MAX; ++i) {
			children[i] = nullptr;
		}
		freq = 1;
	}

	~TrieNode() {
		for (int i = 0; i < MAX; ++i) {
			delete children[i];
		}
	}
};

// Inserts a word into the trie
void insert(string s, TrieNode *root) {
	TrieNode *temp = root;
	for (int i = 0; i < s.length(); ++i) {
		int idx = s[i];
		if (!temp->children[idx]) {
			temp->children[idx] = new TrieNode();
		}
		else {
			temp->children[idx]->freq++;
		}
		temp = temp->children[idx];
	}
}

// This function prints unique prefix for every word stored in Trie.
// Prefixes one by one are stored in prefix[]
void findPrefixesUtil(char prefix[], int ind, TrieNode *root) {
	// Corner case
	if (!root) return;
	// Base case
	if (root->freq == 1) {
		prefix[ind] = '\0';
		cout << prefix << " ";
		return;
	}
	for (int i = 0; i < MAX; ++i) {
		if (root->children[i] != nullptr) {
			prefix[ind] = i;
			findPrefixesUtil(prefix, ind + 1, root->children[i]);
		}
	}
}

// Function to print all prefixes that uniquely represent all words in a[0..n-1]
void findPrefixes(string a[], int n) {
	// Construct a Trie of all words
	TrieNode *root = new TrieNode();
	root->freq = 0;
	for (int i = 0; i < n; ++i) {
		insert(a[i], root);
	}
	// Create an array to store all prefixes
	char prefix[500];
	// Print all prefixes using Trie Traversal
	findPrefixesUtil(prefix, 0, root);
}

// Driver function.
int main() {
	string a[] = {"zebra", "dog", "duck", "dove"};
	int n = sizeof(a) / sizeof(a[0]);
	findPrefixes(a, n);
	return 0;
}