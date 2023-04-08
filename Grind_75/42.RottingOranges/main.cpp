#include <bits/stdc++.h>
using namespace std;

static int sUtil(vector<int>& nums, int target, int l, int r){
        cout << "l, r: " << l << " " << r << endl;
        if (l > r) return -1;
        int mid = (r-l)/2 +1;
        int res = -1;
        if (target == nums[l]) return l;
        if (target == nums[r]) return r;
        if (nums[l] < nums[r] && nums[r] < target) return -1;
        if (nums[l] < nums[r] && nums[l] < target) return -1;
        res = sUtil(nums,target,l,mid-1);
        if (res !=-1) return res;
        res = sUtil(nums,target,mid,r);
        if (res !=-1) return res;
        return -1;

    }
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r){
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        int mid = (r-l)/2;
        if (nums[l] < nums[mid] && nums[mid] < target){
            l = mid;
        }
        if (nums[l] < nums[mid] && nums[l] > target){
            l = mid;
        }
        if (nums[mid] < nums[r] && nums[r] < target){
            r = mid;
        }
        if (nums[mid] < nums[r] && nums[mid] > target){
            r = mid;
        }
        else {
            l++;r--;
        }
    }
    return -1;
}

int main(int arg, char* argv[]){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Result: " << endl;
    cout << search(nums,3);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"