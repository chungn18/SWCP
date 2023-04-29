#include <bits/stdc++.h>
using namespace std;

void comUtil(int ind, int target, vector<int>& nums, vector<int>& resi, vector<vector<int>>& res){
    if (ind == nums.size()) return;
    cout << "target: " << target << ",num: " << nums[ind] << endl;
    if (target == 0){
        //resi.push_back(nums[ind]);
        res.push_back(resi);
        return;
    }
    if (target >= nums[ind]){
        resi.push_back(nums[ind]);
        comUtil(ind,target-nums[ind],nums,resi,res);
        resi.pop_back();
    }
    comUtil(ind+1,target,nums,resi,res);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> resi;
    comUtil(0,target,candidates,resi,res);
    return res;

}

int main(int arg, char* argv[]){
    vector<int> nums = {2,3,5,7};
    cout << "Result: " << endl;
    vector<vector<int> > ans;
    ans = combinationSum(nums,7);
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
