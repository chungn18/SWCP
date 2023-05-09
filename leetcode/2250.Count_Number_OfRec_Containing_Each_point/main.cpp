
#include <bits/stdc++.h>
using namespace std;
int binSearch(vector<int>& vec, int p){
    int l = 0; int r = vec.size()-1;
    int m;
    int ans = 0;
    while ( l <= r){
         m = l + (r-l)/2;
        //cout << "p,l,m,r: " << p << ", " << l << ", " << m << ", " << r << endl;
        //if (rec[r][0] >= p && p > rec[m][0]) return rec.size()-m;
        if (vec[m] >= p){
            r = m-1;
            ans = vec.size()-r-1;
        }
        else {
            l = m+1;
        }
    }
    //cout << "ans: " << ans << endl;
    return ans;
}


vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
    vector<int> res(points.size(),0);
    vector<vector<int>> vec(101);
    sort(rectangles.begin(),rectangles.end());
    for (int i = 0; i <= 100; i++){
        for (int j = 0; j < rectangles.size(); j++){
            if (rectangles[j][1] >= i){
                vec[i].push_back(rectangles[j][0]);
            }
        }
    }

    for (int i = 0; i < points.size(); i++){
        res[i] = vec[points[i][1]].size();
        //sort(vec[points[i][1]].begin(),vec[points[i][1]].end());

        /*for (auto j:vec[points[i][1]])
            cout << j << ' ';
        cout << endl;*/

        res[i] = min (res[i],binSearch(vec[points[i][1]],points[i][0]));
    }

    return res;
}
int main(int arg, char* argv[]){
    vector<vector<int>> recs = {{1,2},{2,3},{2,5}};//{{4,7},{4,9},{8,5},{6,2},{6,4}};
    vector<vector<int>> points = {{2,1},{1,4}};//{{4,2},{5,6}};
    vector<int> res = countRectangles(recs,points);
    cout << "Result: \n";
    for (auto i:res){
            cout << i << ' ';
    }
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"