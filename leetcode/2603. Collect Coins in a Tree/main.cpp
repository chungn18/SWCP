
#include <bits/stdc++.h>
using namespace std;
int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int n = coins.size();
    vector<set<int>> es(n);
    
    for (auto& i:edges){
        es[i[0]].insert(i[1]);
        es[i[1]].insert(i[0]);
    }

    int del = 0;
    queue<int> que;
    for (int i = 0; i < n; i++) 
        if (es[i].size()==1 && coins[i] == 0)
            que.push(i);

    //delete leaves with 0 coin in recursively
    while (!que.empty()){
        int leaf = que.front(); que.pop();
        if (!es[leaf].size()) continue;
        int p = *es[leaf].begin();
        cout << "leaf: " << leaf << ",p: " << p << endl;
        es[p].erase(leaf);
        es[leaf].erase(p);
        del += 2;
        if (es[p].size() == 1 && coins[p] == 0)
            que.push(p);
    }

    // Now we have leaves with coin > 0
    for (int i = 0; i < n; i++) 
        if (es[i].size()==1 && coins[i] == 1)
            que.push(i);

    int sizel = 2;
    while (sizel--){
        int size = que.size();
        while(size--){
            int leaf = que.front(); que.pop();
            int p = *es[leaf].begin();
            if (!es[leaf].size()) continue;
            cout << "leaf: " << leaf << ",p: " << p << endl;
            es[p].erase(leaf);
            es[leaf].erase(p);
            del +=2;
            if (es[p].size() == 1)
                que.push(p);
        }
    }

    return edges.size()*2 - del;

}

int main(int arg, char* argv[]){
    vector<int> coints = {1,0,0,0,0,1};//{0,0,0,1,1,0,0,1};
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,5}};//{{0,1},{0,2},{1,3},{1,4},{2,5},{5,6},{5,7}};
    int ans = collectTheCoins(coints,edges);
    cout << "Result: \n";
    cout << ans << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"