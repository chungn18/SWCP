
#include <bits/stdc++.h>
using namespace std;
int bfs(vector<set<int>>& es, const int v, const int n){
    cout << "v: " << v << endl;
    queue<int> que;
    que.push(v);
    vector<int> dist(n,-1);
    vector<int> parent(n,-1);
    //vector<vector<bool>> visited(n,vector<bool>(n,false));
    dist[v] = 0;
    int ans = INT_MAX;
    while (!que.empty()){
        int s = que.size();
        while (s--){
            int quei = que.front(); que.pop();
            cout << "quei: " << quei << endl;
            for (int i:es[quei]){
                if(dist[i] == -1) {
                    dist[i] = dist[quei] + 1;
                    parent[i] = quei;
                    que.push(i);
                }
                else if (parent[i] != quei && parent[quei] != i){
                    ans = min(ans,dist[quei]+dist[i]+1);
                }                
            }
        }

    }
    return ans == INT_MAX ? -1:ans;
}

int findShortestCycle(int n, vector<vector<int>>& edges) {
    vector<set<int>> es(n);
    for (auto& i:edges){
        es[i[0]].insert(i[1]);
        es[i[1]].insert(i[0]);
    }

    queue<int> que;
    for (int i = 0; i < n; i++){
        if (es[i].size() == 1){
            que.push(i);
        }
    }
    while (!que.empty()){
        int quei = que.front(); que.pop();
        int p = *es[quei].begin();
        es[p].erase(quei);
        es[quei].clear();
        if (es[p].size()==1){
            que.push(p);
        }
    }
    
    int ans = INT_MAX;
    for (int i = 0; i < n ; i++){
        if (es[i].size() > 1){
            int bfsi = bfs(es,i,n);
            if(bfsi !=-1){
                ans = min (ans,bfsi);
            }
        }
    }
    return ans == INT_MAX ? -1:ans;
}

int main(int arg, char* argv[]){
    vector<vector<int>> e = {{5,0},{4,0},{1,5},{6,1},{3,4},{2,6},{2,1},{3,2}};
    //{{0,1},{0,2}};
    //{{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
    //{{1,2},{0,1},{3,2},{1,3}};
    int ans = findShortestCycle(7,e);
    cout << "Result: \n";
    cout << ans << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"