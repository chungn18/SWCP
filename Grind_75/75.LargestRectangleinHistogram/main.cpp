
#include <bits/stdc++.h>
using namespace std;

bool myCom(vector<int>& a, vector<int>& b){
    return a[0] > b[0];
}
int largestRectangleArea(vector<int>& heights){
    vector<vector<int>> vec;
    int len = heights.size();
    for (int i = 0; i < heights.size(); i++){
        vec.push_back({heights[i],i});
    }
    sort(vec.begin(),vec.end(),myCom);
    int res = 0;
    for (int i = 0; i < len; i++){
        int l = vec[i][1], r = vec[i][1];
        int s_max = vec[i][0];
        while(l >= 0 && r < len){
            cout << "i: " << vec[i][1] << ", l: " << l << ", r: " << r << " s_max: " << s_max << endl;
            if (l-1 >=0 && heights[l-1] >= vec[i][0]) l--;
            else if (r+1 < len && heights[r+1] >= vec[i][0]) r++;
            else {
                break;
            }
            int s_cur = vec[i][0]*(r-l+1);
                if(s_cur > s_max) s_max = s_cur;
        }
        if (res < s_max) res = s_max;
    }
    return res;
}


int main(int arg, char* argv[]){

    vector<int> heights = {2,1,5,6,2,3};
    int res = largestRectangleArea(heights);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}
