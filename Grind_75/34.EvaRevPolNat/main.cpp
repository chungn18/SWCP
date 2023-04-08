#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stack>
using namespace std;

int cal(int a, int b, char c){
        switch (c){
        case '+': return a + b; break;
        case '-': return a - b; break;
        case '*': return a*b; break;
        case '/': return a/b; break;
        }
        return 0;
    }
void printStack(stack<int> sta){
    while (!sta.empty()){
        std::cout << sta.top() << " ";
        sta.pop();
    }
    cout << endl;
}
int evalRPN(vector<string>& tokens) {
    string c;
    int val = 0;
    stack<int> sta;
    int op1 = 0, op2 = 0;
    for (int i = 0; i < tokens.size(); i++){
        c = tokens[i];
        if (c == "+" || c == "-" || c == "/" || c == "*"){
            op1 = sta.top(); sta.pop();
            op2 = sta.top(); sta.pop();
            val = cal(op2,op1,c[0]);
            sta.push(val);
        }
        else {
            sta.push(stoi(c));
        }
        printStack(sta);
    }
    return val;
}

int main(int arg, char* argv[]){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "Result: " << evalRPN(tokens) << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"