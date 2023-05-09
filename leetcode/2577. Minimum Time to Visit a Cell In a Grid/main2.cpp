
#include <bits/stdc++.h>
using namespace std;

int minimumTime(vector<vector<int>>& grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
    int m = grid.size();
    int n = grid[0].size();
    vector<int> delR = {-1,1,0,0};
    vector<int> delC = {0,0,-1,1};
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    priority_queue<vector<int>, vector<vector<int>>, greater<>> que;
    que.push({0,0,0});
    visited[0][0] = true;

    while (!que.empty()){
        auto quei = que.top(); que.pop();
        cout << "si: " << quei[0] << ", ri: " << quei[1] << " ,ci: " << quei[2] << endl;
        if (quei[1] == m-1 && quei[2] == n-1) return quei[0];
        for (int i = 0; i < 4; i++){
            int si = quei[0] + 1;
            int ri = quei[1] + delR[i];
            int ci = quei[2] + delC[i];
            if (ri <0 || ri >= m || ci <0 || ci >= n) continue;
            if (!visited[ri][ci]){
                if (si >= grid[ri][ci]) que.push({si,ri,ci});
                else {
                    bool wait = (grid[ri][ci] - si + 1) % 2 == 0;
                    si = grid[ri][ci] + wait;
                    que.push({si,ri,ci});
                }
                visited[ri][ci] = true;
            }
        }
    }

    return -1;
}

int main(int arg, char* argv[]){
    vector<vector<int>> grid = {{0,1,99},{3,99,99},{4,5,6}};
    //{{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    int res = minimumTime(grid);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"