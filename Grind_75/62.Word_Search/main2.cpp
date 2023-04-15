
#include <bits/stdc++.h>
using namespace std;

vector<int> delR = {-1,1,0,0};
vector<int> delC = {0,0,-1,1};

int m, n;
string gword;

bool isValid(int r, int c){
    return (r>=0 && r <m && c >=0 && c <n);
}

bool rec(int r, int c, int wi, vector<vector<char>>& board, vector<vector<bool>>& path){
    if (wi >= gword.size()) return true;
    if (!isValid(r,c)) return false;
    if (board[r][c] != gword[wi] || path[r][c]){
        return false;
    }
    cout << "wi: " << wi << endl;
    cout << "board[" << r << "][" << c << "]: " << board[r][c] << endl;
    path[r][c] = true;
    bool res = false;
    for (int i=0; i<4; i++){
        int ri = r + delR[i];
        int ci = c + delC[i];
        res = res || rec(ri,ci,wi+1,board,path);
    }
    path[r][c] = false;
    /*for (auto i:path){
        for (auto j:i){
            cout << "j: " << j << " ";
            j = false;
        }
        cout << endl;
    }*/
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    gword = word;
    m = board.size();
    n = board[0].size();
    //bool res = false;
    vector<vector<bool>> path(m,vector<bool>(n,false));
    for (int i = 0; i < m; i++){
        for (int j = 0; j <n; j++){
            if (rec(i,j,0,board,path)){
                return true;
            }
        }
    }
    return false;
}

int main(int arg, char* argv[]){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";

    cout << "Result: \n";
    cout << exist(board,word);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"