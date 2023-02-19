#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool isAnagram(string s, string t) {

    if (s.size() != t.size()) return false;
    if (s.size() == 0) return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    
    for (int i =0; i < s.size(); i++){
        if (s[i] != t[i]) return false;
    }
    return true;
        
}

int main(){
    string s = "rat", t = "car";

    cout << *(s.end()-1) << endl;
    cout << "Output: " << isAnagram(s,t) << endl;
    return 1;
}