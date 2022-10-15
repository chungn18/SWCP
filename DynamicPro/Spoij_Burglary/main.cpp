#include <iostream>
#include <cstring>

using namespace std;
int T= 0;
int N =0, D=0;
int W[31];

void Input(){
    cout << "Input you string follow guide" <<endl;
    cout << "The first line is number of test cases -> T" << endl;
    cout << "Each case consists 2 lines" << endl;
    cout << "The first one contains 2 int N and D"<< endl;
    cout << "The second line contains n int representing the weight of all items" << endl;
    cin >> T;
    cin >> N >> D;
    for (int i=0; i <N; i++){
        cin >> W[i];
    }
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