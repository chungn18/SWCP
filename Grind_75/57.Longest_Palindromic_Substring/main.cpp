
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int maxLen = 1;
    string substr;
    substr.push_back(s[0]);
    int l, r;
    for(float i = 0; i < s.size(); i += 0.5){
        l = floor(i-0.5); r = ceil(i+0.5);
        while (l >=0 && r < s.size() && s[l] == s[r]){
            if (maxLen < r-l+1){
                maxLen = r-l+1;
                substr = s.substr(l,maxLen);
            }
            l--;r++;
        }
    }
    return substr;
}

int main(int arg, char* argv[]){
    string s = "cbbd";
    string res;
    cout << "Result: \n";
    res = longestPalindrome(s);
    cout << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"