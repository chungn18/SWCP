
#include <bits/stdc++.h>
using namespace std;

vector<string> nums = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> letterCombinations(string digits) {
    
    vector<string> res;
    if (digits.size() == 0){
        return res;
    }
    int len = digits.size();
    vector<int> n(len,0);
    string c;
    while(n[0] < nums[digits[0]-'0'].size()){
        c.clear();
        for (int i = 0; i< len; i++){
            c += nums[digits[i]-'0'][n[i]];
            }
        res.push_back(c);
        n.back()++;
        if (n.back() >= nums[digits.back()-'0'].size()){
            
            for (int ni = len-1; ni >0; ni--){
                if (n[ni] >= nums[digits[ni]-'0'].size()){
                    n[ni-1]++;
                    n[ni] = 0;
                } 
            }
            n.back() = 0;
        }
    }

    return res;
}

int main(int arg, char* argv[]){
    string s = "23456";
    vector<string> res;
    cout << "Result: \n";
    res = letterCombinations(s);
    for (auto i:res) {
        cout << i << ", ";
    }
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"