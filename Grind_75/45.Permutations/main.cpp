#include <bits/stdc++.h>
using namespace std;


void rec(int ind, vector<int>& can, vector<int>& ares, vector<vector<int>>& ans, int target){
    if (ind >= can.size() || target < 0) return;

    cout << "cani: " << can[ind] << endl;
    if (target == 0){
        ans.push_back(ares);
        return;
    }

    //take candidates idnth;
    ares.push_back(can[ind]);
    rec(ind,can,ares,ans,target-can[ind]);
    ares.pop_back();
    rec(ind+1,can,ares,ans,target);

    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ares;
    rec(0,candidates,ares,ans,target);
    return ans;
}
int main(int arg, char* argv[]){
    vector<int> candidates = {2,3,6,7};
    cout << "Result: " << endl;
    vector<vector<int> > ans;
    ans = combinationSum(candidates,7);
    for (auto i:ans){
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"