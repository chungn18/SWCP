/*KEY:
- Use stack to save indexs that can be continue;
- Use stack to calculate are at heights[i] is smaller than current height.
*/

#include <bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector<int>& heights){
    int res = 0, ind =0;
    heights.push_back(0);
    stack<vector<int>> sta;
    res = heights[ind];
    sta.push({ind,heights[ind]});

    while (++ind < heights.size()){
        if (heights[ind] < sta.top()[1]){
            vector<int> stai;
            int s_cur;
            while(!sta.empty() && sta.top()[1] >= heights[ind]){
                stai = sta.top();
                sta.pop();
                cout << "pop    : {" << stai[0] << "," << stai[1] << "}"<< endl;
                s_cur = (ind-stai[0])*stai[1];
                if (res < s_cur) res = s_cur;
            }
            sta.push({stai[0],heights[ind]});
            cout << "push   : {" << sta.top()[0] << "," << sta.top()[1] << "}"<< endl;
        }
        else if (heights[ind] == sta.top()[1]){
            continue;
        }
        else {
            sta.push({ind,heights[ind]});
            cout << "push   : {" << sta.top()[0] << "," << sta.top()[1] << "}"<< endl;
        }
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
