// Graph structure:
class Graph {
private:
    vector<unordered_set<int>> adjlist; // Adjacency list representation
public:
    Graph(int n) {
        adjlist.resize(n);
    }

    // Get the number of vertices
    int getVertexCount() const {
        return adjlist.size();
    }

    // Get adjacency list
    const vector<unordered_set<int>>& getAdjList() const {
        return adjlist;
    }
};

// Depth-First Search (DFS) explore function
void explore(Graph& G, int u, vector<bool>& visited, int& numVisited, int& numEdges) {
    visited[u] = true;
    numVisited++; // Increment vertex count

    for (int v : G.getAdjList()[u]) { // Iterate through neighbors of u
        numEdges++; // Increment edge count
        if (!visited[v]) {
            explore(G, v, visited, numVisited, numEdges); // Recursive DFS call
        }
    }
}

// Function to check if a graph is a tree
bool is_tree(Graph& G) {
    int n = G.getVertexCount();

    vector<bool> visited(n, false);
    int numVisited = 0;
    int numEdges = 0;

    explore(G, 0, visited, numVisited, numEdges); // Start DFS from node 0 (assuming graph is 0-indexed)

    // Check if all nodes are visited and edge count is valid
    // Divide number of edges by 2 because this graph is undirected
    if (numVisited == n && numEdges / 2 == n - 1) {
        return true;
    }
    return false;
}
