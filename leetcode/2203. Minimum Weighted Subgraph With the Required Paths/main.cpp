
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

void dijkstra(int v, vector<vector<pll>>& adj, vector<ll>& wei){
    wei[v] = 0;
    priority_queue<pll,vector<pll>,greater<>> que;
    que.push({0,v});
    while (!que.empty()){
        auto [w,vi] = que.top();
        que.pop();
        if(w != wei[vi]) continue;
        for (auto [ui,wi]:adj[vi]){
            if (wei[ui] > wei[vi] + wi){
                wei[ui] = wei[vi] + wi;
                que.push({wei[ui],ui});
            }
        }
    }

}

long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
    vector<vector<pll>> adj1(n);
    vector<vector<pll>> adj2(n);
    for (auto& i:edges){
        adj1[i[0]].push_back({i[1],i[2]});
    }
    for (auto& i:edges){
        adj2[i[1]].push_back({i[0],i[2]});
    }
    vector<vector<ll>> wei(3,vector<ll>(n,1e12));
    dijkstra(src1,adj1,wei[0]);
    dijkstra(src2,adj1,wei[1]);
    dijkstra(dest,adj2,wei[2]);
    ll ans = LONG_MAX;
    if (wei[2][src1] == 1e12 || wei[2][src2] == 1e12) return -1;
    for (int i = 0; i < n; i++){
        ll temp = wei[0][i]+wei[1][i]+wei[2][i];
        ans = min(ans,temp);
    }
    /*for (int i = 0; i < 3; i++){
        cout << "wei[" << i << "]: ";
        for (int j = 0; j < n; j++){
            cout << wei[i][j] << ' ';
        }
        cout << endl;
    }*/
    return ans;
}


int main(int arg, char* argv[]){
    int n = 6;
    vector<vector<int>> edges = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
    int src1 = 0, src2 = 1, dest = 5;
    cout << minimumWeight(n,edges,src1,src2,dest) << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"