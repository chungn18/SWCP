#include <bits/stdc++.h>
using namespace std;
struct location {
    int r;
    int c;
};

vector<int> delR = {-1,1,0,0};
vector<int> delC = {0,0,-1,1};

static bool isValid(int r, int c, int rS, int cS){
    return (r >= 0 && r < rS && c >=0 && c <cS);
}

int orangesRotting(vector<vector<int>>& grid) {
    int fre = 0, rot =0;
    location loc;
    queue<location> que;
    for (int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++){
            if (grid[i][j] == 1) fre++;
            if (grid[i][j] == 2){
                rot++;
                loc.r = i; loc.c =j;
                que.push(loc);
            }
        }
    cout << "Number of Rotting Oranges: " << rot << endl;
    cout << "Number of Fresh Oranges: " << fre << endl;
    
    if (fre == 0) return 0;
    if (rot == 0) return -1;
    
    int cnt = 0, res = 0;
    cout << "Queue: \n";
    while (!que.empty()){
        location qfr;
        if (cnt == fre) return res;
        int s = que.size();
        while(s--){
            qfr = que.front(); que.pop();
            cout << "qr: " << qfr.r << ", " << "qC: " << qfr.c << endl;
            for (int i = 0; i <4 ; i++){
                int ri = qfr.r + delR[i];
                int ci = qfr.c + delC[i];
                if (isValid(ri,ci,grid.size(),grid[0].size())){
                    if (grid[ri][ci] == 1){
                        grid[ri][ci] = 2;
                        location newLoc = {ri,ci};
                        que.push(newLoc);
                        cnt++;
                    }
                }
            }
        }
        res++;
    }
    return -1;

}
int main(int arg, char* argv[]){
    vector<vector<int> > grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Result: " << endl;
    cout << orangesRotting(grid);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"