
#include <bits/stdc++.h>
using namespace std;

vector<string> nums = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> letterCombinations(string digits) {
    
    vector<string> res;
    if (digits.size() == 0){
        return res;
    }
    res.push_back("");
    for (auto dii:digits){
        vector<string> temp;
        for (auto c:nums[dii-'0']){
            
            for (auto resi:res){
                temp.push_back(resi+c);
            }
        
        }
        res.clear();
        res = temp;
        
    }
    return res;
}

int main(int arg, char* argv[]){
    string s = "23456789";
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