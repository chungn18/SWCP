#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int V = 0;
vector<vector<int> > Array;

void Input(){
    cout << "Input graph in array:\n";
    cin >> V;
    vector<int> vecTemp;
    for (int i=0; i<V; i++){
        vecTemp.clear();
        for (int j =0; j<V; j++){
            int temp;
            cin >> temp;
            vecTemp.push_back(temp);
        }
        Array.push_back(vecTemp);
    }
}

void printBFS(vector<bool> visited, vector<int> pre, int s)
{
    for(int v=0; v <visited.size(); v++){
        if (visited[v]==false){
            cout << "Khong co duong dan tu " << s << " di den " << v << endl;
        }
        else {
            cout << "Duong dan di tu " << s << " di den " << v << ": " << v;
            int f=v;
            while (pre[f] !=-1){
                cout << "->" <<pre[f];
                f = pre[f];
            }
            cout << endl;
        }
    }
}

void BFS(vector<vector<int> > arr, uint s) {
    int V = arr[0].size();
    queue<int> que;
    vector<int> pre(V*(V-1)/2,-1);
    vector<bool> visited(V,0);
    que.push(s);
    int u;
    visited[u] = true;
    while (que.size() >0) {
        u = que.front();
        que.pop();
        for (int v=0; v<V; v++){
            if(arr[u][v] >0 && visited[v] == false){
                que.push(v);
                pre[v] = u;
                visited[v] = true;
            }
        }       
    }
    printBFS(visited, pre, s);
}

int main(){
    Input();
    cout << "\n-----------OUTPUT--------------" << endl;
    BFS(Array,0);
}
/*graph to test
8
0 1 1 0 0 0 0 0
1 0 1 1 0 0 0 0
1 1 0 0 1 0 0 0
0 1 0 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 0
*/