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

void DFS(vector<vector<int> > &graph, int s){
    
    vector<int> visited(graph[0].size(),0);
    stack<int> sta;
    int n;
    sta.push(s);
    while(!sta.empty()){
        n = sta.top();
        visited[n]++;
        if(visited[n]==1){
            cout << n << " ";
        }
        sta.pop();
        for (int i=0; i< graph[0].size(); i++)
            if(visited[i] ==0 && graph[n][i] == 1 && n !=i){
                sta.push(i);
            }
    }
}

int main(){
    cout << "\n----------- INPUT --------------" << endl;
    InputV();
    cout << "\n----------- OUTPUT --------------" << endl;
    DFS(Array,1);
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