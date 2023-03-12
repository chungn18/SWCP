#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = INT_MIN, summax = INT_MIN;
    int begin = 0;
    if (nums.size() == 1) return nums[0];
    for (int i = 0; i <nums.size(); i++){
        if (sum < 0) {
            begin = i;
            sum = nums[i];
        }
        else sum += nums[i];
        if (sum > summax) summax=sum;
    }
    return summax;
    }

int main(int arg, char* argv[]){

    vector<int> nums = {-4,-3,-2,-5,-10};
    cout << "Output: " << maxSubArray(nums) << endl;
    return 1;
}