// https://www.geeksforgeeks.org/trie-insert-and-search/

// T.C => O(m), S.C => O(ALPHABET_SIZE * n * m)

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