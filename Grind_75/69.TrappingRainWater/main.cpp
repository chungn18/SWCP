
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int le = height[0], ri = height.back(), res = 0;
    int n = height.size();
    cout << "n: " << n << endl;
    vector<int> levec(n,0),rivec(n,0),minvec(n,0);

    for (int i=1; i<n;i++){
        if(height[i] > le){
            levec[i] = le;
            le = height[i];
        }
        else levec[i] = le;

        if(height[n-1-i] >ri){
            rivec[n-1-i] = ri;
            ri = height[n-1-i];
        }
        else rivec[n-1-i] = ri;
    }

    for (int i=0; i<n;i++){
        minvec[i] = min(levec[i],rivec[i]);
        res += max(0,minvec[i]-height[i]);
    }
    cout << "left vector: ";
    for (auto i:rivec){
        cout << i << " ";
    }
    cout << endl;

    return res;
}
int main(int arg, char* argv[]){

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = trap(height);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"