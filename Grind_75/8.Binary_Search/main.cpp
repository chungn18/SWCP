// problem: https://leetcode.com/problems/binary-search/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000;
vector<int> num(N,0);
int length;
int target;
int search(vector<int>& nums, int target) {
    int l=0, r = length-1;
    int m = (l+r)/2;
    while (l <= r){
        m = (l + r)/2;
        cout << "l: " << l << ",m " << m << ",r " << r << endl;
        if (nums[m] == target) return m;
        else if(nums[m] < target){
            l = m +1;
        }
        else {
            r = m-1;
        }
    }
    return -1;
}
void inArr(){
    unsigned int N;
    cout << "Type n-length of array\n";
    cin >> length;
    cout << "Type elements of array\n";
    for (int i=0; i<length; i++){
        cin >> num[i];
    }
    cout << "Type target to search\n";
    cin >> target;
}
int main(){
    inArr();
    int m = search(num,target);
    cout << "Output: " << m << endl;
    return 1;
}