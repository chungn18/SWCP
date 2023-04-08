#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }

vector<vector<int> > merge(vector<vector<int> >& intervals){
    
    queue<vector<int>> que;
    sort(intervals.begin(),intervals.end(),cmp);
    for (auto i:intervals){
        que.push(i);
    }
    vector<vector<int>> res;
    res.push_back(que.front());
    vector<int> quei, resi;
    while(!que.empty()){
        resi = res.back();
        quei = que.front();
        que.pop();
        if (resi[1] >= quei[0]){
            resi = {min(resi[0],quei[0]),max(resi[1],quei[1])};
            res.pop_back();
            res.push_back(resi);
        }
        else {
            res.push_back(quei);
        }
    }
    return res;
}

int main(int arg, char* argv[]){
    vector<vector<int> > intervals = {{1,4},{0,2},{3,5}};
    cout << "Result: " << endl;
    vector<vector<int> > ans;
    ans = merge(intervals);
    for (auto i:ans){
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"