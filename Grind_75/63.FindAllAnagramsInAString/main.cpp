
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if (s.size() < p.size()) return res;
    unordered_map<char,int> hashp, hashsi;
    char head, tail;
    int lenP = p.size();
    int match =0, temp = 1;
    
    for (int i = 0; i < lenP; i++) {
        hashp[p[i]]++;
        hashsi[s[i]]++;
    }
    //cout << "sumP: " << sumP << endl;
    for (int i = 0; i <= s.size() - p.size(); i++){
        //unordered_map<char,int> hashsi;
        if (i >0){
            head = s[i-1];
            tail = s[i+lenP-1];
            hashsi[head]--;
            hashsi[tail]++;
        }

        if (match == 1){
            if (hashsi[head] != hashp[head] || hashsi[tail] != hashp[tail])
            {
                temp = 0;
                match = 0;
            }
        }

        else {
            for(auto c:p){
                if (hashsi[c] != hashp[c]){
                    temp = 0;
                    match = 0;
                    break;
                }
            }
        }
        

        if (temp == 1){
            res.push_back(i);
            hashsi = hashp;
            match = 1;
        }
        temp = 1;

    }
    return res;

}

int main(int arg, char* argv[]){
    string s = "cbaebabacd", p = "abc";
    vector<int> res;
    cout << "Result: \n";
    res = findAnagrams(s,p);
    for (auto i:res) {
        cout << i << ", ";
    }
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"