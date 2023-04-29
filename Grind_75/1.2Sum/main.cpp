#include <bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++){
        if (mp.find(target-nums[i]) != mp.end()){
            res.push_back(mp[target-nums[i]]);
            res.push_back(i);
            return res;
        }
        mp[nums[i]] = i;
    }
}

int main(){
	vector<int> nums = {3,2,4};
    vector<int> res;
    res = twoSum(nums,6);
    for (auto i:res) cout << i << ' ';
    cout << endl;
	return 0;
}