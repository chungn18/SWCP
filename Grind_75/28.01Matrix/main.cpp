#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int> > resolve;
    if (intervals.size() == 0){
        resolve.push_back(newInterval);
        return resolve;
    }

    if (newInterval[1] < intervals[0][0]) {
        intervals.insert(intervals.begin(),newInterval);
        cout << "Insert new interval into begin of intervals\n";
        return intervals;
    }

    if (newInterval[0] > intervals[intervals.size()-1][1]) {
        intervals.push_back(newInterval);
        cout << "Insert new interval into end of intervals\n";
        return intervals;
    }

    stack<vector<int>> res;
    res.push(intervals[0]);
    vector<int> n, nTop;
    bool temp = 1;
    for (int i = 0; i < intervals.size();i++){

        nTop = res.top();
        if (newInterval[0] < intervals[i][0] && temp == 1){
            n = newInterval;
            temp = 0;
            i--;
        }
        else {
            n = intervals[i];
        }

        if (nTop[1] < n[0])
        res.push(n);
        else if (nTop[0] < n[0] && nTop[1] < n[1]){
            res.pop();
            n[0] = nTop[0];
            res.push(n);
        }
    }
    for (int i= res.size()-1; i >= 0; i--){
        resolve.push_back(res.top());
        res.pop();
    }
    reverse(resolve.begin(), resolve.end());
    return resolve;
}

int main(int arg, char* argv[]){
    vector<vector<int> > intervals = {{1,5}};
    vector<int> newInterval = {2,7};
    vector<vector<int> > resolve = insert(intervals,newInterval);
    for (auto i:resolve){
        for (int j=0; j<2; j++){
            cout << i[j] << " ";
        }
        cout << endl;
    }
    return 1;
}