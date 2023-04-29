
#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int si = 0, pi =0;
    //Check string is null case
    if ((s.size() == 0 && p.size() !=0) || (p.size() == 0 && s.size() !=0)){
        return false;
    }
    else if (s.size() == 0) return true;

    if (p.find('*') == string::npos && s.size())

    while (si < s.size() && pi < p.size()){
    
    if (p[pi] == '?') {pi++;si++;}
    else if (p[pi] == '*'){
        pi++;
    }
    else if (s[si] != p[pi]) return false;
    else {pi++;si++;}
    }
    return true;
}

int main(int arg, char* argv[]){

    string s = "aa", p = "a";
    bool res = isMatch(s,p);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}
