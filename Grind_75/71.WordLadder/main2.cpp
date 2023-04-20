
#include <bits/stdc++.h>
using namespace std;
bool isValid(string a, string b){
    unordered_map<char,int> mapa;
    unordered_map<char,int> mapb;
    int count = 0;
    for (int i = 0; i <a.size();i++){
        mapa[a[i]]++;
        mapb[b[i]]++;
    }
    for (int i=0; i<a.size(); i++){
        if(--mapb[a[i]] <0) count++;
        if(count > 1) return false;
    }
    if (count == 1) return true;
    else return false;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_map<string, int> mp, vis;
        for(auto x: wordList) mp[x] = 1;
        if(!mp[endWord]) return 0;
        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = 1;
        int ans = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                string u = q.front();
                q.pop();
                if(u == endWord) {
                    return ans + 1;
                }
                for(int i=0; i<n; i++) {
                    for(char c='a'; c<='z'; c++) {
                        string v = u;
                        v[i] = c;
                        if(!vis[v] and mp[v]) {
                            q.push(v);
                            vis[v] = 1;
                            cout << "Push word: " << v << endl;
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
int main(int arg, char* argv[]){

    string beginWord = "leet", endWord = "code";
    vector<string> wordList = {"lest","leet","lose","code","lode","robe","lost"};
    int res = ladderLength(beginWord, endWord, wordList);
    cout << "Result: \n";
    cout << res << endl;
    cout <<"Check isValid(): \n";
    cout << isValid("mist","miss") << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"