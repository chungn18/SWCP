#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
      unordered_set<int> seen;
      queue<int> que; que.push(amount);
      int cnt = 0, s = 0;
      while(!que.empty()){
        s = que.size();
        while(s--){
          int temp = que.front(); que.pop();
          if (temp == 0) return cnt;
            for (auto i:coins){
                if (temp >= i && seen.find(temp-i) == seen.end()){
                    que.push(temp-i);
                    seen.insert(temp-i);
                }
            }
        }
        cnt++;
      }
      return -1;
    }

int main(int arg, char* argv[]){
    int amount = 11;
    vector<int> coins = {1,2,5};
    cout << "Result: " << endl;
    cout << coinChange(coins,amount);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"