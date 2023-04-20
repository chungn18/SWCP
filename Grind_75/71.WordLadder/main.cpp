
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

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    bool checkw = false;
        for(auto i:wordList){
            if (endWord == i){
            checkw = true;
              break;  
            }
        }
        if (!checkw) return 0;
    
    queue<pair<int,int>> que;
    que.push({-1,1});
    pair<string,int> quei;

    vector<bool> visited(wordList.size(),false);

    while(!que.empty()){
        if (que.front().first == -1){
            quei.first = beginWord;
        }
        else  quei.first = wordList[que.front().first];
        quei.second = que.front().second;
        que.pop();
        cout << "quei: " << quei.first << endl;
        //count += level;
        if(isValid(quei.first,endWord)) return ++quei.second;
        for(int i = 0; i<wordList.size();i++){
            
            if (isValid(quei.first,wordList[i]) && !visited[i]){
                que.push({i,quei.second+1});
                visited[i] = true;
            }
        }
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