#include <iostream>

using namespace std;
const int MAX = 2000;
int n = 0;
string X[10];
string Y[10];
int Nteca;
int F[MAX][MAX];

void inputData(){
    cout << "Input number of test case and 2 strings X, Y as syntax: " << endl;
    cout << "Number of test case" << endl;
    cout << "Xi Yi (with i from 1 to N, i is int)" << endl; 
    cin >> Nteca;
    for (int i=0; i< Nteca; i++){
        cin >> X[i];
        X[i].insert(0," "); //make string begin from at 1
        cin >> Y[i];
        Y[i].insert(0," "); //make string begin from at 1
    }
}
void Trace(string x, string y)
{
    int i = x.length()-1;
    int j = y.length()-1;
    int count =1;
    while (i>0 || j>0){
        if (F[i][j]==F[i-1][j-1]){
            i--;j--;
        }
        else if ((j>0)&&F[i][j]==(F[i][j-1]+1))
        {
            cout << count << ".Insert at " << i << " char " << y[j] << endl;
            i--;
            count++;
        }
        else if ((i>0)&&(j>0)&&F[i][j]==(F[i-1][j]+1)){
            cout << count << ".Replace at " << i << " char " << x[i] << endl;
            i--;j--;
            count++;
        }
        else {
            cout << count << ".Delete at " << i << " char " << x[i] << endl;
            count++;
        }
    }


}
int resolve(string x, string y){
    memset(F,0,MAX*MAX);
    for (int i=0; i<=x.length(); i++)
    F[i][0]=i;
    for (int j=0; j<=y.length(); j++)
    F[0][j]=j;
    
    for (int i =1; i <= x.length(); i++){
        
        for (int j=1; j<= y.length(); j++ )
        {
            F[i][j] = F[i-1][j-1];
            if(x[i]!=y[j]){
                F[i][j] = min(min(F[i][j-1],F[i-1][j]),F[i-1][j-1])+1;
            }
        }
    }
    cout << "Number of operaters: " << F[x.length()][y.length()] << endl;
    return F[x.length()][y.length()];
}

int main(){
    inputData();
    for (int i=0; i<Nteca; i++){
    resolve(X[i],Y[i]);
    Trace(X[i],Y[i]);
    }

}