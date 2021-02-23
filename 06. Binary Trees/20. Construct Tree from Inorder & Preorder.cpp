// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

// T.C => O(n^2), S.C => O(n)

Node* solve(int in[], int pre[], int inS, int inE, int preS, int preE) {
	if (inS > inE) return NULL;
	int rootData = pre[preS];
	int rootIndex = -1;
	// Finding root index in inorder
	for (int i = inS; i <= inE; ++i) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}
	// length of left part of inorder == length of left part preorder
	// (lInE - lInS) => left part of inorder
	// (lPreE - lPreS) => left part of preorder
	// lInE - lInS = lPreE - lPreS
	// So, lPreE = lInE - lInS + lPreS
	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	Node *root = new Node(rootData);
	root->left = solve(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = solve(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}


Node* buildTree(int in[], int pre[], int n) {
	return solve(in, pre, 0, n - 1, 0, n - 1);
}