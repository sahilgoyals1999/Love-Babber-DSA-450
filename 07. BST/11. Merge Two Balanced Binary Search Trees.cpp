// https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

// T.C => O(n+m), S.C => O(m+n)

// function that stores inorder traversal of a tree rooted with node
void inorder(Node* node, int in[], int &index) {
	if (!node) return;
	// first recur on left child
	inorder(node->left, in, index);
	// store node data
	in[index] = node->data;
	// now recur on right child
	inorder(node->right, in, index);
}

// function to merge two sorted arrays into one
int *merge(int in1[], int in2[], int m, int n) {
	// in[] is going to contain result
	int *in = new int[m + n];
	int i = 0, j = 0, k = 0;
	// Traverse through both arrays
	while (i < m && j < n) {
		// Pick the smaler element and put it in in
		if (in1[i] < in2[j]) {
			in[k] = in1[i];
			i++;
		}
		else {
			in[k] = in2[j];
			j++;
		}
		k++;
	}
	// If there are more elements in first array
	while (i < m) {
		in[k] = in1[i];
		i++;
		k++;
	}
	// If there are more elements in second array
	while (j < n) {
		in[k] = in2[j];
		j++;
		k++;
	}
	return in;
}

// function that constructs Balanced Binary Search Tree from a sorted array
Node* sortedArrayToBST(int in[], int start, int end) {
	// Base Case
	if (start > end) return NULL;
	// Get the middle element and make it root
	int mid = start + (end - start) / 2;
	Node *root = new Node(in[mid]);
	// Recursively construct the left subtree and make it left child of root
	root->left = sortedArrayToBST(in, start, mid - 1);
	// Recursively construct the right subtree and make it right child of root
	root->right = sortedArrayToBST(in, mid + 1, end);
	return root;
}

// This function merges two balanced BSTs with roots as root1 and root2
// m and n are the sizes of the trees respectively
Node* mergeTrees(Node *root1, Node *root2, int m, int n) {
	// Store inorder traversal of first tree in an array in1[]
	int *in1 = new int[m];
	int i = 0;
	inorder(root1, in1, i);
	// Store inorder traversal of second tree in another array in2[]
	int *in2 = new int[n];
	int j = 0;
	inorder(root2, in2, j);
	// Merge the two sorted array into one
	int *in = merge(in1, in2, m, n);
	// Construct a tree from the merged array and return root of the tree
	return sortedArrayToBST(in, 0, m + n - 1);
}