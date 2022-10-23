#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};
Graph::Graph(int V){
    this->V =V;
    adj.resize(V);
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
void Graph::BFS(int s){
    int u = s;
    vector<bool> visited(V,0);
    queue<int> que;
    que.push(s);
    cout << "Visit graph from " << s << ": ";
    while (que.size()>0){
        u = que.front();
        que.pop();
        if (u>=V) {
            cout << u << endl;
            break;
            }
        cout << u << "->";
        visited[u] = 1;
        for(auto v:adj[u]){
            if(visited[v]==false)
            que.push(v);
        }
    }
}
int main(){
    Graph g(4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.BFS(2);
}