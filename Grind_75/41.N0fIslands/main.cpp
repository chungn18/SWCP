#include <bits/stdc++.h>
using namespace std;
vector<int> delX= {-1,1,0,0};
vector<int> delY= {0,0,-1,1};
bool isValid (int m, int n, int lenR, int lenC){
        return (m >=0 && m < lenR && n >=0 && n < lenC);
    }

void DFS(int m, int n, vector<vector<char>>& grid, int& cnt){
    
    if (grid[m][n] == '1'){
        pair<int,int> p = make_pair(m,n);
        stack<pair<int,int>> sta; sta.push(p);
        while (!sta.empty()){
            p= sta.top(); sta.pop();
            grid[p.first][p.second] ='2';
            for (int i = 0; i<4; i++){
              if(isValid(p.first+delX[i],p.second+delY[i],grid.size(),grid[0].size())){
                if (grid[p.first+delX[i]][p.second+delY[i]] == '1') {
                  sta.push(make_pair(p.first+delX[i],p.second+delY[i]));
                  grid[p.first+delX[i]][p.second+delY[i]] ='2';
                }
              }
            }
        }
        cnt++;
    }
}

int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    int lenR = grid.size();
    int lenC = grid[0].size();
    for (int i = 0; i < lenR; i++){
        for (int j = 0; j < lenC; j++){
            DFS(i,j,grid,cnt);
        }
    }

    for (auto i: grid){
        for (auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }

    return cnt;
}
int main(int arg, char* argv[]){
    vector<vector<char> > grid = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    cout << "Result: " << endl;
    cout << numIslands(grid);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"