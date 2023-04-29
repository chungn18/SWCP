#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > Array;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    vector<vector<int>> ans;
    vector<int> mergeItv = newInterval;
    bool merged = false;
    for (auto vi:intervals){
        if (vi[1] < mergeItv[0]){
            ans.push_back(vi);
        }
        else if (vi[0] > mergeItv[1]){
            if (!merged){
                ans.push_back(mergeItv);
                merged = true;
            }
            ans.push_back(vi);
        }
        else { 
            mergeItv[0] = min(mergeItv[0],vi[0]);
            mergeItv[1] = max(mergeItv[1],vi[1]);
        }
    }
    if (!merged) ans.push_back(mergeItv);

    return ans;
}


int main(int arg, char* argv[]){
    vector<vector<int>> res;
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10}};
    vector<int> newInterval = {4,8};
    res = insert(intervals,newInterval);
    for (auto i:res){
        for (auto j:i){
            cout << j << ' ';
        }
        cout << endl;
    }
    return 1;
}