
#include <bits/stdc++.h>
using namespace std;
long long countOperationsToEmptyArray(vector<int>& nums) {
    unordered_map<int,int> mp;
    int len = nums.size();
    long long res = len;
    for (int i=0; i < len; i++){
        mp[nums[i]] = i;
    }
    sort(nums.begin(),nums.end());
    for (int i = 1; i < len; i++){
        if (mp[nums[i]] < mp[nums[i-1]]){
            res += len-i;
        }
    }
    return res;
}

int main(int arg, char* argv[]){
    vector<int> nums = {1,2,4,3};
    long long res = countOperationsToEmptyArray(nums);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"