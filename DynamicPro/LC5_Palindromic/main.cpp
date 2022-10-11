#include <iostream>
#include <cstring>

using namespace std;
string longestPalindrome(string s) {
    int size = s.length();
    int F[size+1][size+1];
    memset(F,0,size*size);
    int imax =0, jmax=0, lenmax=1;
    for (int i=size/2; i>=0; i--){
        for (int j=i; j<=size;j++){
            if (i==j){
                F[i][j]=1;
            }
            else if((j==i+1) && (lenmax <2)){
                F[i][j] = 2;
                lenmax = 2;
                imax=i;
                jmax=j;
            }
            else if ((F[i][j] == (F[i+1][j-1]+2))&& ((j-i+1)>lenmax)){
                F[i][j] = F[i+1][j-1]+2;
                lenmax = j-i+1;
                imax =i;
                jmax =j;
            }
            else {
                F[i][j]=F[i][j-1];
            }
        }
    }
    return s.substr(imax,jmax);
}

int main(){
    string c = longestPalindrome("babad");
    cout << c <<endl;
}