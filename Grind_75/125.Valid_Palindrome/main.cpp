#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool isValid(char& c){
    if (c>= 'A' && c <= 'Z'){
        c = c+32;
        return true;
    }
    else if ( c >= 'a' && c <= 'z' || (c >= '0' && c <= '9')) return true;
    else return false;
}
bool isPalindrome(string s) {
    int l = 0; 
    int r = s.size()-1;
    while (l < r){
        cout << "s[" << l << "]:" << s[l] << ", s[" << r << "]:" << s[r]  << endl;
        if (!isValid(s[l])){
            l++;
        }
        else if (!isValid(s[r])){
            r--;
        }
        else if (s[l] != s[r]){
            return false;
        }
        else {l++;r--;};
    }
    return true;
}

int main(){
    string s = "0P";
    cout << "\nOutput: " << isPalindrome(s) << endl;
    return 1;
}