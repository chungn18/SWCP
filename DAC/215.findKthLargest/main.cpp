#include <bits/stdc++.h>
using namespace std;

int quickselect(vector<int>& nums, int l, int r, int k){
    //cout << "l:" << l << ",r:" << r << endl;
    if (l>=r) return nums[l];
    int pivot = nums[l + (r-l)/2];
    int li = l-1; int ri = r+1;
    while (li<ri){
        while(nums[++li] > pivot);
        while(nums[--ri] < pivot);
        if (ri>li) swap(nums[li],nums[ri]);
    }
    int ki = ri - l +1;
    if (ki >= k) quickselect(nums,l,ri,k);
    else quickselect(nums,ri+1,r,k-ki);
}

int findKthLargest(vector<int>& nums, int k) {
    return quickselect(nums, 0, nums.size()-1,k);
    }
int main(int arg, char* argv[]){
    vector<int> nums = {3,2,1,5,6,4};
    cout << "Result: " << endl;
    cout << findKthLargest(nums,2);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"