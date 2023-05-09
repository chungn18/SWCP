
#include <bits/stdc++.h>
using namespace std;
string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size();
    
    string res(n,'a');
    for (int c = 1; c < n; c++){
        for (int r = 0; r < c; r++){
            if (lcp[r][c] == 0 && res[r] == res [c]){
                res[c]++;
            }
        }
    }
    //cout << "res: " << res << endl;
    vector<vector<int>> lcp2(n,vector<int>(n,0));
    for (int c = n-1; c >= 0; c--){
        for (int r = c; r >= 0; r--){
            if (r == c){
                lcp2[r][c] = n-c;
            }
            else if (res[r] != res[c]){
                lcp2[r][c] = 0;
            }
            else {
                if (c == n-1) lcp2[r][c] = 1;
                else lcp2[r][c] = min(n-c,lcp2[r+1][c+1]+1);
            }
            //cout << lcp2[r][c] << " ";
            if (lcp2[r][c] != lcp[r][c] || lcp2[r][c] != lcp[c][r]) return "";
        }
        //cout << endl;
    }
    return res;
}

int main(int arg, char* argv[]){
    vector<vector<int>> lcp = //{{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,3}};
    //{{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}};
    {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
    cout << 'z' - 0 << endl;
    string res = findTheString(lcp);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"