# // C++ program to print the paths between two vertices
#include<iostream>
#include<list>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
    int V;    // No. of vertices
    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index);
  public:
    Graph(int V);   // Constructor
    bool pathExist; //variable to indicate if path exist or not
    // function to add an edge to graph
    void addEdge(int v, int w);
    void printAllPaths(int v1, int v2);

};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function to print all paths from 'v1' to 'v2'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and index is current
// index in path[]
void Graph::printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index) {
    // Mark the current node as visited and store it in path[]
    visited[v1] = true;
    path[index] = v1;
    index++;
    // If current vertex is same as v2, then print
    // current path[]
    if (v1 == v2) {
        int i;
        if (!pathExist)
            cout << "Following are the paths between " << path[0] << " and " << path[index - 1] << endl;
        pathExist = true;
        for (i = 0; i < index - 1; i++)
            cout << path[i] << "->";
        cout << path[i] << endl;
    } else { // If current vertex is not v2
        // Recur for all the vertices adjacent
        // to this vertex
        list<int>::iterator i;
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, v2, visited, path, index);
    }
    // Remove current vertex from path[] and mark it as unvisited
    index--;
    visited[v1] = false;
}

// DFS traversal of the vertices reachable from v.
// It uses recursive prinAllPathsUtil
void Graph::printAllPaths(int v1, int v2) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create an array to store paths
    int *path = new int[V];

    // Initialize path[] as empty
    int index = 0;

    pathExist = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(v1, v2, visited, path, index);


}


int main() {
    // Create a graph given in the above diagram
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(6, 4);
    g.addEdge(5, 7);
    g.addEdge(7, 6);
    g.addEdge(0, 2);
    g.addEdge(2, 6);
    int v1 = 0, v2 = 6;
    g.printAllPaths(v1, v2);
    if (!g.pathExist) {
        cout << "There is no path exist between " << v1 << " and " << v2;
    }
    return 0;
}
