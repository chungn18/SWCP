#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        vector<int> res;
        vector<int>::iterator redi = res.begin();
        for(auto i:nums){
            if (i == 0) {
                res.insert(res.begin(),0);
                redi++;
            }
            if (i == 2) res.push_back(2);
            res.insert(redi,1);
        }
        nums = res;
    }

int main(int arg, char* argv[]){
    vector<int> nums = {2,0,2,1,1,0};
    cout << "Result: " << endl;
    sortColors(nums);
    for (auto i:nums){
        cout << i << " ";
    }
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"