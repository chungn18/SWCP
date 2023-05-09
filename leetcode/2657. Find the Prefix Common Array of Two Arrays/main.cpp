
#include <bits/stdc++.h>
using namespace std;
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int len = A.size();
    vector<int> C(len,0);
    unordered_map<int,int> posA;
    unordered_map<int,int> posB;
    for (int i = 0; i < len; i++){
        posA[A[i]] = i;
        posB[B[i]] = i;
    }
    if (A[0] == B[0]) C[0] = 1;
    for (int i = 1; i < len; i++){
        C[i] = C[i-1];
        if (posB[A[i]] == posA[B[i]] && posB[A[i]] == i){
            C[i]++;
        }
        else {
            if (posB[A[i]] <= i) C[i]++;
            if (posA[B[i]] <= i) C[i]++;
        }
    }
    return C;
}

int main(int arg, char* argv[]){
    vector<int> A = {2,3,1};
    vector<int> B = {3,1,2};
    vector<int> C = findThePrefixCommonArray(A,B);
    cout << "Result: \n";
    for (auto i:C){
        cout << i << ' ';
    }
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"