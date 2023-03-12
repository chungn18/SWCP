#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > Array;

//Add adge to a undirected graph
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
}

void InputV(){
    int m, n;
    cout << "Input graph in array\n";
    cout << "Input number of row (r) and number of collum of gapth\n";
    cin >> m >> n;
    vector<int> vecTemp;
    for (int i=0; i<m; i++){
        vecTemp.clear();
        for (int j =0; j<n; j++){
            int temp;
            cin >> temp;
            vecTemp.push_back(temp);
        }
        Array.push_back(vecTemp);
    }
}

void printGraph(vector<vector<int> > &graph)
{
    for(auto i:graph){
        for (auto j:i)
            cout << j << " ";
        cout << endl;
    }
}

void BFS(vector<vector<int> > &graph, int s){
    queue<int> que;
    vector<int> visited(graph[0].size(),0);
    que.push(s);
    visited[s] = 1;
    int ele;
    cout << "Sequence of visited: " << s;
    while(!que.empty()){
        ele = que.front();
        que.pop();
        for (int i = 0; i <graph[0].size(); i++){
            if(visited[i] == 0 &&  graph[ele][i] == 1){
                que.push(i);
                cout << "->" << i;
                visited[i] = 1;
            }
        }
    }
    cout << "|" << endl;
}

int main(){
    cout << "\n----------- INPUT --------------" << endl;
    InputV();
    cout << "\n----------- OUTPUT --------------" << endl;
    BFS(Array,1);
    //printGraph(Array);
}
/*graph to test
6 6
1 1 1 0 0 0
1 1 1 1 0 0
1 1 1 0 1 0
0 1 0 1 1 0
0 0 1 1 1 0
0 0 0 0 0 1
*/