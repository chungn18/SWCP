
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int,int>> points;
    multiset<int> pq{0};
    vector<vector<int>> ans;
    for (auto i:buildings){
        points.push_back({i[0],-i[2]});
        points.push_back({i[1],i[2]});
    }
    sort(points.begin(),points.end());
    int curHeight = 0;
    for (auto vi:points){
        int xi = vi.first;
        int hei = vi.second;
        if (hei < 0 ){
            pq.insert(-hei);
        }
        else {
            pq.erase(pq.find(hei));
        }

        auto it = *pq.rbegin();
        if (it != curHeight){
            ans.push_back({xi,it});
            curHeight = it;
        }
    }
    return ans;
}

int main(int arg, char* argv[]){
    vector<vector<int>> buildings = {{0,2,3},{2,5,3}};//{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    cout << "Result: \n";
    vector<vector<int>> res;
    res = getSkyline((buildings));
    for (auto i:res){
        for (auto j:i)
            cout << j << ' ';
        cout << endl;
    }
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"