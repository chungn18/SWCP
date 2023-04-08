#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> res;
vector<int> resi;
void solv(vector<bool> fre, vector<int>& nums){
    if (resi.size() == nums.size()){
        res.push_back(resi);
        return;
    }
    
    for(int i = 0; i < nums.size(); i++){
        if(!fre[i]){
            resi.push_back(nums[i]);
            fre[i] = true;
            solv(fre,nums);
            resi.pop_back();
            fre[i] = false;
        }
    }
    return;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> fre(nums.size(),0);
    solv(fre,nums);
    return res;
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
