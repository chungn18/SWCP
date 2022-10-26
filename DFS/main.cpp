#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;
void Input(int& v, vector<vector<int> > &arr){
    vector<int> temp;
    int t;
    cout << "Input number of verticles of graph:\n";
    cin >> v;
    cout << "Input each verticle of graph:\n";
    for (int i=0; i< v; i++){
        temp.clear();
        for(int j=0; j<v; j++){
            cin >> t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }
}
void DFS_recursion(const vector<vector<int> >& graph, const int s, const int N, vector<int>& parent) {
    
    vector<bool> visited (N,0);  
    for (int v=0; v< N; v++){
        if (visited[s] == 0 && graph[s][v] > 0){
            visited[s] = true;
            if(s >0) parent[v] = s;
            DFS_recursion(graph,v,N,parent);
        }
    }
    return;
}
void printDFS(vector<int> parent, int s){
    int p = parent[s];
    cout << s << "->";
    while (parent[p] != -1){
        p = parent[p];
        cout << p << "->";
    }
    cout << endl;
}
int main(){
    int N;
    vector<vector<int> > graph;
    Input(N,graph);
    vector<int> parent(N,-1);
    DFS_recursion(graph,0,N,parent);
    printDFS(parent, 0);
    return 0;
}