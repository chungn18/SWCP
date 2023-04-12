
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    
    if (m==1||n==1) return 1;

    vector<vector<int>> dp(m,vector<int>(n,1));

    for (int r = m-2; r >=0; r--){
        for (int c = n-2; c >=0; c--){
            dp[r][c] = dp[r][c+1]+ dp[r+1][c];
        }
    }
    return dp[0][0];
}

int main(int arg, char* argv[]){
    cout << "Result: \n";
    cout << uniquePaths(3,8) << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"