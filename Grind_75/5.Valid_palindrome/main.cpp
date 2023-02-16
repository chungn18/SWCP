#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {

    if(s.size() == 0) return 1;

    transform(s.begin(),s.end(),s.begin(),::tolower);

    cout << "String after convert to lower: " << s << endl;

    for(string::iterator it = s.begin(); it != s.end(); it++){
        if ((*it >='0' && *it <= '9') || (*it >='A' && *it <= 'Z') || (*it >='a' && *it <= 'z')){
        }
        else {
            s.erase(it);
            it--;
        }
    }
    cout << "String after delete no-alphanumber: " << s << endl;

    string::iterator it1, it2;
    for (it1 = s.begin(), it2 = s.end()-1; it2 - it1 >0; it1++, it2--){
        cout << "*it1: " << *it1 << ", *it2: " << *it2 << endl;
        if (*it1 != *it2) return 0;
    }
    
    return 1;
};

int main(){
    string s = "A man, a plan, a canal: Panama";
    cout << "Input string: " << s << endl;
    bool bo = isPalindrome(s);
    cout << "Output: " << bo << endl;
}