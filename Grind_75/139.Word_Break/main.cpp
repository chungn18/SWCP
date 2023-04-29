
#include <bits/stdc++.h>
using namespace std;

bool wordCheck(string s, vector<string>& wordDict, int ind, int si){
    cout << "si: " << si << endl;
    cout << "ind: " << ind << endl;
    if (si >= s.size()) return true;
    if (ind >= wordDict.size()) return false;
    string sub = s.substr(si,wordDict[ind].size());
    cout << "sub: " << sub << endl;
    if (sub == wordDict[ind]){
        si += sub.size();
        ind = 0;
    }
    else {
        ind++;
    }
    for (int i = 0; i < wordDict.size(); i++)
    return wordCheck(s,wordDict,i,si);
}

bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1,false);
    dp[s.size()] = true;
    for (int si = s.size()-1; si >= 0; si--){
        for (int wi = 0; wi <wordDict.size(); wi++){
            int leni = wordDict[wi].size();
            string sub = s.substr(si,leni);
            cout << "sub: " << sub << endl;
            if (sub.size() == leni && sub == wordDict[wi]) {
                dp[si] = dp[si+leni];
                if (dp[si]) break;
            }
            else dp[si] = false;
        }
    }
    cout << "dp: ";
    for(auto i: dp){
        cout << i << " ";
    }
    cout << endl;
    return dp[0];
}

int main(int arg, char* argv[]){
    string s = "cars";
    vector<string> wordDict = {"car","ca","rs"};
    cout << "Result: ";
    cout << wordBreak(s,wordDict) << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"