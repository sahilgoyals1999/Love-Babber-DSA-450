// https://www.geeksforgeeks.org/word-break-problem-trie-solution/

// T.C => O(m*m), S.C => O(ALPHABET_SIZE * n * m)

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
class TrieNode {
public:
	TrieNode **children;
	bool is_terminal;

	TrieNode() {
		children = new TrieNode*[ALPHABET_SIZE];
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			children[i] = NULL;
		}
		is_terminal = false;
	}

	~TrieNode() {
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
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

// Returns if the word is in the trie
bool search(string s, TrieNode *root) {
	TrieNode *temp = root;
	for (int i = 0; i < s.length(); ++i) {
		int idx = s[i] - 'a';
		if (!temp->children[idx]) {
			return false;
		}
		else temp = temp->children[idx];
	}
	return temp->is_terminal;
}

// returns true if string can be segmented into space separated words, otherwise returns false
bool wordBreak(string s, TrieNode *root) {
	int size = s.length();
	// Base case
	if (size == 0)  return true;
	// Try all prefixes of lengths from 1 to size
	for (int i = 1; i <= size; ++i) {
		if (search(s.substr(0, i), root) && wordBreak(s.substr(i, size - i), root)) {
			return true;
		}
	}
	// If we have tried all prefixes and none of them worked
	return false;
}

// Driver program to test above functions
int main() {
	string dictionary[] = {"mobile", "samsung", "sam",
	                       "sung", "ma\n", "mango",
	                       "icecream", "and", "go", "i",
	                       "like", "ice", "cream"
	                      };
	int n = sizeof(dictionary) / sizeof(dictionary[0]);
	TrieNode *root = new TrieNode();
	// Construct trie
	for (int i = 0; i < n; ++i) {
		insert(dictionary[i], root);
	}
	wordBreak("ilikesamsung", root) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}