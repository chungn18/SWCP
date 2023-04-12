
#include <bits/stdc++.h>
using namespace std;

struct rc {
        int r;
        int c;
};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    const int r = matrix.size()-1;
    const int c = matrix[0].size()-1;
    vector<rc> con = {{0,0},{0,c},{r,c},{r,0}};
    vector<int> res;
    int ri = 0, ci = 0;
    if (r == 0 || c==0){
        for (auto i:matrix){
            for (auto j:i) res.push_back(j);
        }
        return res;
    }

    //res.push_back(matrix[ri][ci]);
    //cout << "matrix[" << ri << "][" << ci << "]: " << matrix[ri][ci] << endl;
    int delRi = 0, delCi = 0;
    int conner = 0;
    while (res.size() < matrix.size()*matrix[0].size()){
        res.push_back(matrix[ri][ci]);
        //cout << "matrix[" << ri << "][" << ci << "]: " << matrix[ri][ci] << endl;
        
        
        if (ri == con[0].r && ci == con[0].c && conner ==0){
            delRi = 0;
            delCi = 1;
            conner = 1;
            if (ri==0 && ci==0)
            con[0].r++;
            else{
                con[0].r++;con[0].c++;
            }

        }
        else if (ri == con[1].r && ci == con[1].c && conner == 1){
            delRi = 1;
            delCi = 0;
            conner =2;
            con[1].r++; con[1].c--;
        }
        else if (ri == con[2].r && ci == con[2].c && conner == 2){
            delRi = 0;
            delCi = -1;
            conner = 3;
            con[2].r--;con[2].c--;
        }
        
        else if (ri == con[3].r && ci == con[3].c && conner == 3){
            delRi = -1;
            delCi = 0;
            conner = 0;
            con[3].r--;con[3].c++;

        }

        ri = ri + delRi;
        ci = ci + delCi;
        
    }
    return res;  

}
int main(int arg, char* argv[]){
    vector<vector<int> > matrix = /*{{1,2,3,4},{5,6,7,8},{9,10,11,12}}*/ {{3},{2}};
    cout << "Result:";
    vector<int> res;
    res = spiralOrder(matrix);
    for (auto i:res){
        cout << i << " ";
    }

    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"