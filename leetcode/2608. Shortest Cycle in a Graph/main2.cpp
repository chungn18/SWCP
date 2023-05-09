
#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>& es, vector<vector<bool>>& visited, const int v, const int n){
    cout << "v: " << v << endl;
    stack<int> sta;
    sta.push(v);
    vector<int> dist(n,0);
    int ans = INT_MAX;
    int cur = 0;
    while (!sta.empty()){
        
        int stai = sta.top();
        sta.pop();
        cur++;
        dist[stai] = cur;
        cout << "stai: " << stai << endl;
        for (int i:es[stai]){
            if(!visited[stai][i]){
                if(dist[i] != 0) {
                    ans = min (ans, cur-dist[i]+1);
                    cout << "ans: " << ans << endl;
                }

                visited[i][stai] = true;
                visited[stai][i] = true;
                sta.push(i);        
            }
        }

    }
    return ans == INT_MAX ? -1:ans;
}

int findShortestCycle(int n, vector<vector<int>>& edges) {
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    vector<vector<int>> es(n);
    for (auto& i:edges){
        es[i[0]].push_back(i[1]);
        es[i[1]].push_back(i[0]);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n ; i++){
        int dfsi = dfs(es,visited,i,n);
        if(dfsi !=-1){
            ans = min (ans,dfsi);
        }
    }
    return ans == INT_MAX ? -1:ans;
}

int main(int arg, char* argv[]){
    vector<vector<int>> e = //{{4,1},{5,1},{3,2},{5,0},{4,0},{3,0},{2,1}};
    //{{0,1},{0,2}};
    //{{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
    {{1,2},{0,1},{3,2},{1,3}};
    int ans = findShortestCycle(5,e);
    cout << "Result: \n";
    cout << ans << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"