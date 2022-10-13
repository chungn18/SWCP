#include <iostream>
#include <cstring>

using namespace std;
string str;
void Input(){
    cout << "Input you string: ";
    cin >> str;
}

int getLen(string s, int L, int R){
    while((L>=0) && (R<s.length()) && (s[L]==s[R])){
        L--;
        R++;
    }
    return R-L-1;
}

string longestPalindrome(string s) {
    if (s.length()<1) return "";
    int lenmax =0, len =0, start=0, end=0;
    for (int i=0; i<s.length(); i++){
        len = max(getLen(s,i,i),getLen(s,i,i+1));
        if (len>lenmax){
            lenmax =len;
            start = i-(lenmax-1)/2;
        }
    }

    return s.substr(start,lenmax);
}

int main(){
    while(1){
    Input();
    string c= longestPalindrome(str);
    cout << c <<endl;
    }
}