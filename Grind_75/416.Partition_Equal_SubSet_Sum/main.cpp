
#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i:nums) sum += i;
        if (sum%2 == 1) return false;
        unordered_set<int> dp;
        unordered_set<int> dpNext;
        int dpi = 0;
        dpNext.insert(0);
        for (auto i:nums){
            dp = dpNext;
            for(auto j:dp){
                dpi = i+j;
                if (dpi == sum/2) return true;
                dpNext.insert(dpi);
                
            }
        }
        return false;
    }

int main(int arg, char* argv[]){
    vector<int> nums = {1,2,3,5};
    cout << "Result: ";
    cout << canPartition(nums) << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"