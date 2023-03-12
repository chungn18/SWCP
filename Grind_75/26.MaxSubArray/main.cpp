#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string addBinary(string a, string b, int base) {

    int aChar, bChar;
    string res;
    int sum = 0, mod = 0;
    int i = a.length()-1;
    int j = b.length()-1;
    while (i >=0 || j >=0 || mod > 0){
        aChar = (i >= 0 ? a[i]-'0' : 0);
        bChar = (j >= 0 ? b[j]-'0' : 0);
        sum = aChar + bChar + mod;
        res = char(sum%base + '0') + res;
        if (sum > base) mod = sum/base;
        else mod = 0;
        i--; j--; 
    }
    cout << res << endl;
    return res;
}

int main(int arg, char* argv[]){

    string a,b;
    cin >> a >> b;
    cout << "Output: " << addBinary(a,b,10) << endl;
    return 1;
}