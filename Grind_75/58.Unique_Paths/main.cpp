
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){
    
    int i = 0, j = height.size()-1;
    int areaM = (j-i)*min(height.front(),height.back());
    while (i < j){
        if (height[i]> height[j]){
            j--;
        }
        else i++;
        if ((j-i)*min(height[i],height[j]) > areaM){
            areaM = (j-i)*min(height[i],height[j]);
        }
    }
    
    return areaM;
    
}

int main(int arg, char* argv[]){
    vector<int> height = {2,3,4,5,18,17,6};
    cout << "Result: \n";
    cout << maxArea(height) << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"