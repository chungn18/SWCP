
#include <bits/stdc++.h>
using namespace std;

bool check (int a,int b){
    int temp = sqrt(a+b);
    return (a+b) == temp*temp;
}

void rec(vector<int> nums, int cur, int& count){

    if (cur >= nums.size()){
        count++;
        //cout << "OK!\n";
        return;
    }
    for (int i = cur; i < nums.size(); i++){
        cout << "cur: " << cur << ", i: " << i << endl;
        if ( i == cur || nums[i] != nums[cur]){
            swap(nums[cur],nums[i]);
            if (cur == 0 || (cur >0 && check(nums[cur-1],nums[cur]))){
                rec(nums,cur+1,count);
            }
        }
    }
}

int numSquarefulPerms(vector<int>& arr) {
    int count = 0;
    // sorting arr
    sort(arr.begin(),arr.end());
    rec(arr,0,count);
    
    return count;
}


int main(int arg, char* argv[]){
    vector<int> nums = {1,17,8};
    int res = numSquarefulPerms(nums);
    cout << "Result: " << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"