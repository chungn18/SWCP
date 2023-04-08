#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stack>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int sum;
        int i=0, j=0, k=nums.size()-1;
        for (i = 0; i < nums.size(); i++){
            j = i+1;
            k = nums.size()-1;
            while (j < k){
                sum = nums[i]+nums[j]+nums[k];
                if (sum == 0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
                else if (sum > 0){
                    k--;
                }
                else j++;
            }
        }
        return res;
    }

int main(int arg, char* argv[]){
    vector< int> nums = {-1,0,1,2,-1,-4};
    cout << "Result: " << endl;
    for (auto i:res)
    for (auto j:i)
    cout << j;
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"