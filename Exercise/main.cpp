#include <iostream>
#include <vector>
using namespace std;

int N;//the number of test cases
int B;//number system
string S;//first integer
string D;//second integer

void InputData(){
	cin >> B >> S >> D;
}
vector<int> Solve(int b, string s, string d)
{
    int sign = 0;
    int iRev =0, jRev = 0, cary =0, sum =0, resLen =  0; 
    int iInt =0, jInt=0;
    if (s[0]=='-'){
        sign++;
        s = s.substr(1);
    }
    if (d[0]=='-'){
        sign++;
        d = d.substr(1);
    }
    //cout <<"s: " << s << ", d: " << d << endl;
    int sLen = s.length();
    int dLen = d.length();
    vector<int> result(sLen+dLen+10,0);
    for(int i= dLen-1; i>=0; i--){
        iInt = d[i] - '0';
        for (int j=sLen-1; j>=0; j--){
            jInt = s[j] - '0';
            sum = iInt*jInt + cary + result[iRev+jRev];
            result[iRev+jRev] = sum%b;
            cary = sum/b;
            jRev++;
        }
        
        if(cary>0){
            result[iRev+jRev] = cary;
            cary =0;
        }
        //cout << "Result: ";
        //for (int k:result)  cout << k <<" ";
        //cout <<endl;
        iRev++;
        jRev=0;
        
    }
    vector<int>::iterator k = result.end()-1;
    while(*k ==0){
        result.pop_back();
        k--;
    }
    //cout << "Result for return: ";
    //    for (int l:result)  cout << l <<" ";
    result.push_back(sign);
    return result;
}
int main(){
	int i;
    int sign;
    char signChar;
    vector<vector<int> > result;
	cin >> N;
	for(int i = 0; i < N; i++){
		InputData();//input function
        //cout << "B: " << B << ", S: " << S << ", D: " << D << endl;
        result.push_back(Solve(B, S, D));
	}
    for (vector<int> i:result){
        sign = i.back();
        i.pop_back();
        if (sign%2)
        {
            cout << '-';
        }
        for(vector<int>::iterator j = i.end(); j != i.begin(); j--) 
        {
            cout << char(*j+'0');
        }
        cout << endl;

    }
	return 0;
}