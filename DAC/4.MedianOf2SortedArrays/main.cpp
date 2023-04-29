#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int len1 = nums1.size();
  int len2 = nums2.size();
  if (len1 == 0) {
      return (nums2[floor((len2-1)/2)] + nums2[ceil((len2-1)/2)]);
  }
  if (len2 == 0) {
      return (nums1[floor((len1-1)/2)] + nums1[ceil((len1-1)/2)]);
  }
  int len = len1 +len2;
  float half = (len-1)/2 + 1;
  double res;
  int l1 = 0; int l2 = 0;
  int r1 = len1-1;
  int r2 = len2-1;

  while (1){
      int m1 = (r1+l1)/2;
      int m2 = (r2+l2)/2;
      cout << "m1: " << m1 << ", m2: " << m2 << endl;

      if (nums1[m1] < nums2[m2]){
        half -= (m1-l1+1);
        l1 = m1+1;
        if (l1 >= len1){
          
        }
      //res1 = nums2[m2];
      }
      else {
        half -= (m2-l2+1);
        l2 = min(m2+1,len2);
      //res2 = min(nums1[l1],nums2[l2]);
      }
      if (len%2){
        if (half == 0) return min(nums1[l1],nums2[l2]);
      }
      else {
        if (half <= -0.5){
          cout << "l1: " << l1 << ", r1: " << r1 << ", l2: " << l2 << ", r2: " << r2 << endl;
        res = (nums1[l1]+nums2[l2])/2;
        return res;
        }
      }
  }

}
int main(int arg, char* argv[]){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    cout << "Result: " << endl;
    cout << findMedianSortedArrays(nums1,nums2);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"