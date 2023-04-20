
#include <bits/stdc++.h>
using namespace std;
int calculate(string s) {
    int res =0, cur = 0, sign = 1;
    stack<int> sta;
    for (auto i:s){
        if (i >= '0' && i<= '9'){
            cur = cur*10 + (i -'0');
        }
        else if ( i == '+' || i == '-'){
            res += sign*cur;
            cout << "in +/-, sign: " << sign << ",res: " << res  << ", cur: " << cur << endl;
            if (i == '-') {
                sign = -1;
            }
            else sign = 1;
            cur = 0;
        }
        else if(i == '('){
            sta.push(res);
            sta.push(sign);
            cout << "res: " << res << endl;
            cout << "sign: " << sign << endl;
            res = 0; sign =1;
        }
        else if(i == ')'){
            res += cur*sign;
            int signt = sta.top(); sta.pop();
            int rest = sta.top(); sta.pop();
            cout << "in = ), res: " << res << ", cur: " << cur << ", sign: "<< sign << endl;
            cur =0;
            res = res*signt;
            res += rest;
        }
    }
    return res + (cur*sign);
}

int main(int arg, char* argv[]){

    string s = "1-(     -2)";
    int res = calculate(s);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"