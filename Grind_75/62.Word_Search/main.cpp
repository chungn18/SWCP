
#include <bits/stdc++.h>
using namespace std;

vector<int> delR = {-1,1,0,0};
vector<int> delC = {0,0,-1,1};

int m, n;

bool isValid(int r, int c){
    return (r>=0 && r <m && c >=0 && c <n);
}

bool exist(vector<vector<char>>& board, string word) {
    
    stack<pair<int,int>> sta;
    pair<int,int> stai;
    m = board.size();
    n = board[0].size();
    if (word.size() > m*n) return false;
    vector<vector<bool>> check(m,vector<bool>(n,false));
    
    for (int r = 0; r < m; r++){
        for (int c = 0; c < n; c++){
            if (word[0] == board[r][c]){
                sta.push({r,c});
                //check[r][c]= true;
            }
        }
    }
    int wi = 1;
    while (!sta.empty()){
        if (word.size()==1) return true;
        stai = sta.top();
        check[stai.first][stai.second]= true;
        cout << "stai[" << stai.first << "][" << stai.second << "]: " << board[stai.first][stai.second] << endl;
        cout << "wi: " << wi << endl;
        sta.pop();
        int temp = 0;
        for (int i = 0; i < 4; i++){
            
            int ri = stai.first + delR[i];
            int ci = stai.second + delC[i];
            if (isValid(ri,ci)){
                if (board[ri][ci] == word[wi] && check[ri][ci] == false){
                    sta.push({ri,ci});
                    cout << "push [" << ri << "][" << ci<< "]: " << board[ri][ci] << endl;
                    temp++;
                    //check[ri][ci] = true;
                    
                    //break;
                }
            }
        }
        if(temp>0){
            wi++;
            if (wi >= word.size()) return true;
            //temp=0;
        }
        else {
            check[stai.first][stai.second]= false;
        }

    }
    return false;
}

int main(int arg, char* argv[]){
    vector<vector<char>> board = {{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'}}/*{{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}}*/;
    string word = "aaaaaaaaaaaaaa";

    cout << "Result: \n";
    cout << exist(board,word);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"