
#include <bits/stdc++.h>
using namespace std;

void rec(int ind, vector<int>& nums, vector<vector<int>>& subset, vector<int>& subi){
    if (ind >= nums.size()){
        return;
    }
    
    subi.push_back(nums[ind]);
    subset.push_back(subi);
    rec(ind+1,nums,subset,subi);
    subi.pop_back();
    rec(ind+1,nums,subset,subi);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> resi;
    res.push_back(resi);
    rec(0,nums,res,resi);
    return res;
}

int main(int arg, char* argv[]){
    vector<int> nums = {1,2,3};
    cout << "Result: \n";
    vector<vector<int> > res;
    res = subsets(nums);
    for (auto i:res){
        for (auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"