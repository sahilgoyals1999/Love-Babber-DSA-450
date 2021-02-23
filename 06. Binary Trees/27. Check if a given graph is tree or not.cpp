// https://www.geeksforgeeks.org/check-given-graph-tree/

// T.C => O(n), S.C => O(n)

// A recursive function that uses vis[] and parent to
// detect cycle in subgraph reachable from vertex v.
bool dfs(int v, bool vis[], int parent) {
	// Mark the current node as visited
	vis[v] = true;
	// Recur for all the vertices adjacent to this vertex
	for (auto &i : adj[v]) {
		// If an adjacent is not visited, then recur for that adjacent
		if (!vis[i]) {
			if (dfs(i, vis, v)) return true;
		}
		// If an adjacent is visited and not parent of current vertex, then there is a cycle.
		else if (i != parent) return true;
	}
	return false;
}

// Returns true if the graph is a tree, else false.
bool isTree() {
	// Mark all the vertices as not visited and not part of recursion stack
	bool *vis = new bool[V];
	for (int i = 0; i < V; ++i) {
		vis[i] = false;
	}
	// The call to dfs serves multiple purposes.
	// It returns true if graph reachable from vertex 0 is cyclcic.
	// It also marks all vertices reachable from 0.
	if (dfs(0, vis, -1)) return false;
	// If we find a vertex which is not reachable from 0 (not marked by dfs(), then we return false
	for (int u = 0; u < V; ++u) {
		if (!vis[u]) return false;
	}
	return true;
}