#include <bits/stdc++.h>
using namespace std;


void rec(int ind, vector<int>& nums, vector<int>& resi, vector<vector<int>>& ans){
    if (resi.size()== nums.size()){
        ans.push_back(resi);
        return;
    }
    resi.push_back(nums[ind]);
    nums.erase(nums.begin()+ind);
    for (int i = 0; i < nums.size(); i++){
        if (i != ind){
            rec(i,nums,resi,ans);
        }
    }
    nums.insert()
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> resi;
    rec(0,nums,resi,ans);
    return ans;
}
int main(int arg, char* argv[]){
    vector<int> nums = {1,2,3};
    cout << "Result: " << endl;
    vector<vector<int> > ans;
    ans = permute(nums);
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