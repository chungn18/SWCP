#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string S;//first integer

bool isValid(string s) {
    stack<char> st;
    char c;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it){
        if (*it ==  '(' || *it == '[' || *it == '{'){
            st.push(*it);
            //cout << "Push new character: " << st.top() << endl;
        }

        else if ((*it ==  ')' || *it == ']' || *it == '}') && !st.empty()) {
            c = st.top();
            st.pop();
            //cout << "Close character: " << *it << endl;
            if (*it == ')' && c != '(') return false;
            if (*it == ']' && c != '[') return false;
            if (*it == '}' && c != '{') return false;
        }

        else return false;
    }

    if (st.empty()) return true;
    else return false;
}

int main(){

	string str;
    cout << "Input your string: " << endl;
	cin >> str;
	cout << "Output: " << isValid(str) << endl;
	return 0;
}