
#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    vector<int> candi(ratings.size(),1);
    int ans = ratings.size();

    for (int i = 1; i < ratings.size(); i++){
        if (ratings[i] > ratings[i-1]){
            candi[i] = candi[i-1]+1;
        }
    }
    
    for (int i = ratings.size()-2; i >= 0; i--){
        if (ratings[i] > ratings[i+1]){
            candi[i] = max(candi[i],candi[i+1]+1);
        }
    }
    return accumulate(candi.begin(),candi.end(),0);
}

int main(int arg, char* argv[]){
    vector<int> ratings = {1,3,2,2,1};//{1,2,2};
    int res = candy(ratings);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"