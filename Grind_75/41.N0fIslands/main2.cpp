#include <bits/stdc++.h>
using namespace std;

void DFS(int r, int c, vector<vector<char>>& grid){
    grid[r][c] = '0';
    if (r-1 >=0 ? grid[r-1][c] == '1':false){
        DFS(r-1,c,grid);
    }
    if (r+1 < grid.size() ? grid[r+1][c] == '1':false){
        DFS(r+1,c,grid);
    }
    if (c-1 >= 0 ? grid[r][c-1] == '1':false){
        DFS(r,c-1,grid);
    }
    if (c+1 < grid[0].size() ? grid[r][c+1] == '1':false){
        DFS(r,c+1,grid);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    for (int r = 0; r < grid.size(); r++){
        for (int c=0; c < grid[0].size(); c++){
            if (grid[r][c] == '1'){
                ans++;
                DFS(r,c,grid);
            }
        }
    }
    return ans;
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