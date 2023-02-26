#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s, t;

bool isAnagram(string s, string t) {

    vector<int> arr(26,0);

    
    if (s.size() != t.size()) return 0;

    for (int i=0; i < s.size(); i++){
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }

    for (int i=0; i < 26; i++){
        if (arr[i] != 0){
            cout << "Element of value not equal 0: " << arr[i] << endl;
            return 0;
        }
    }
    return 1;
        
}
void inStr(){
    cout << "Type your input is 2 strings\n";
    cin >> s >> t;
    cout << "Your input...\n";
    cout << "String s: " << s << endl;
    cout << "String t: " << t << endl;
}
int main(){

    inStr();
    cout << "Output: " << isAnagram(s,t) << endl;
    return 1;
}