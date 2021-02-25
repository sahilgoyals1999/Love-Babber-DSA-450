// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

// T.C => O(row*col), S.C => O(row*col)

class TrieNode {
public:
	TrieNode *left, *right;
	bool is_terminal;

	TrieNode() {
		left = right = NULL;
		is_terminal = false;
	}

	~TrieNode() {
		delete left;
		delete right;
	}
};

bool insert(int arr[], int n, TrieNode *root) {
	TrieNode *temp = root;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0) {
			if (temp->left == NULL) {
				temp->left = new TrieNode();
			}
			temp = temp->left;
		}
		else {
			if (temp->right == NULL) {
				temp->right = new TrieNode();
			}
			temp = temp->right;
		}
	}
	if (temp->is_terminal) {
		return false;
	}
	temp->is_terminal = true;
	return true;
};

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
	TrieNode *root = new TrieNode();
	vector<vector<int>> ans;
	for (int i = 0; i < row; ++i) {
		if (insert(M[i], col, root)) {
			vector<int> v(col);
			for (int j = 0; j < col; ++j) {
				v[j] = M[i][j];
			}
			ans.push_back(v);
		}
	}
	return ans;
}