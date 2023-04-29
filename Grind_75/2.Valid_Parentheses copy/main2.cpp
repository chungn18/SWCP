#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string S;//first integer

bool isValid(string s) {
    vector<char> vec;
    for (auto c:s){
        if (vec.size() == 0) vec.push_back(c);
        else if (c == ')' || c == '}' || c == ']'){
            if (vec.back() == '(' && c == ')'){
                vec.pop_back();
            }
            else if (vec.back() == '[' && c == ']'){
                vec.pop_back();
            }
            else if (vec.back() == '{' && c == '}'){
                vec.pop_back();
            }
            else return false;{}
        }
        else {
            vec.push_back(c);
        }
    }
    if (vec.size() == 0) return true;
    else return false;
}

int main(){

	string str;
    cout << "Input your string: " << endl;
	cin >> str;
	cout << "Output: " << isValid(str) << endl;
	return 0;
}