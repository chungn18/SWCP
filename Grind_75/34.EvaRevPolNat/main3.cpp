// A C++ Program to detect cycle in a graph
#include <bits/stdc++.h>
using namespace std;

class Graph {
	// No. of vertices
	int V;

	// Pointer to an array containing adjacency lists
	list<int>* adj;

	// Used by isCyclic()
	bool isCyclicUtil(int v, bool visited[], bool* rs);

public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}

// DFS function to find if a cycle exists
bool Graph::isCyclicUtil(int v, bool visited[],
						bool* recStack)
{
	cout << "v: " << v << endl;
	if (visited[v] == false) {
		// Mark the current node as visited
		// and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this
		// vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i) {
			if (!visited[*i]
				&& isCyclicUtil(*i, visited, recStack))
				return true;
			else if (recStack[*i])
				return true;
		}
	}

	// Remove the vertex from recursion stack
	recStack[v] = false;
	return false;
}

// Returns true if the graph contains a cycle, else false
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited
	// and not part of recursion stack
	bool* visited = new bool[V];
	bool* recStack = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function
	// to detect cycle in different DFS trees
	for (int i = 0; i < V; i++)
		if (!visited[i]
			&& isCyclicUtil(i, visited, recStack)){
				cout << "\nVisited: \n";
				for(int itr = 0; itr < V; itr++){
					cout << visited[itr] << " ";
				}
				cout << "\nrecStack: \n";
				for(int itr = 0; itr < V; itr++){
					cout << recStack[itr] << " ";
				}

			return true;
			}
	
	return false;
}

// Driver code
int main()
{
	// Create a graph
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.addEdge(2, 0);
	

	// Function call
	if (g.isCyclic())
		cout << "\nGraph contains cycle\n";
	else
		cout << "\nGraph doesn't contain cycle\n";
	return 0;
}
