
#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int sign = 1;
    int i = 0;
    while (s[i] == ' '){
        i++;
    }
    if (s[i] == '-'){
        sign = -1;
        i++;
    }
    else if (s[i] == '+'){
        sign = 1;
        i++;
    }
    long res = 0;

    while (s[i] >='0' && s[i] <= '9'){
        res = res*10 + (s[i] -'0');
        i++;
        if (sign*res < INT_MIN) return INT_MIN;
        if (sign*res > INT_MAX) return INT_MAX;
        
    }
    return sign*res;

    }
int main(int arg, char* argv[]){
    string s = "3.14159";
    cout << "Result:";
    cout << myAtoi(s) << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"