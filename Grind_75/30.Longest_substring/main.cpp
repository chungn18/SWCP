#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stack>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charMap;
        int start = 0, maxLen = 0, i;
        for (i = 0; i <s.length(); i++){
            if (charMap.count(s[i])){
                maxLen = max (maxLen,i -  start);
                start = charMap[s[i]] ++;
            }
            else {
                charMap[s[i]] = i;
            }
            
            cout << "start: " << start << ", i: " << i << ", maxLen: " << maxLen << endl;
        }
        
        return maxLen;
    }

int main(int arg, char* argv[]){
    string s = "abcabcbb";
    cout << "Result: " << lengthOfLongestSubstring(s) << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"