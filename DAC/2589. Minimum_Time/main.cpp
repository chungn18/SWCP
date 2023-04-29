#include <bits/stdc++.h>
using namespace std;

int findMinimumTime(vector<vector<int>>& tasks) {
    sort (tasks.begin(),tasks.end(),[](auto& a, auto& b) {return a[1] < b[1];});
    vector<bool> works(2001,false);
    int ans = 0;
    for (auto vi:tasks){
        int olap = 0;
        for (int j = vi[0]; j <= vi[1]; j++){
            if (works[j]) olap++;
        }
        int need = vi[2] - olap;
        int ei = vi[1];
        while (need > 0){
            if (!works[ei]){
                ans++;
                need--;
                works[ei] = true;
            }
            ei--;
        }
    }
    return ans;
}

int main(int arg, char* argv[]){
    vector<vector<int>> tasks = {{1,18,5},{3,15,1}};
    cout << "Result: " << endl;
    cout << findMinimumTime(tasks);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"