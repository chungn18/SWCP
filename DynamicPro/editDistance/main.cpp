#include <iostream>

using namespace std;
const int MAX = 1000;
int Wmax;
int n = 0;
int w[MAX];
int v[MAX];
int F[MAX][MAX]; //mang luu gia tri Vmax trong cac goi {0,1,2,...,n-1} co khoi luong w(i) voi i{0,1,2,..,n-1}

void inputData(){
    cout << "Input data follow syntax" << endl;
    cout << "Line 1: Wmax n" << endl;
    cout << "Line i: w[i] v[i]" << endl;
    cin >> Wmax;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
        cin >> v[i];
    }
}
void printRes()
{
    int i=n;
    int j=Wmax;
    cout << "Max value: " << F[n][Wmax] << endl;
    cout << "w v" <<endl;
    while (i >0){
        if (F[i][j] != F[i-1][j]){
            cout << w[i] <<" " << v[i] <<endl;
            j = j- w[i];
        }
        --i;
    }

}
void resolve(){
    memset(F,0,MAX*MAX);
    for (int i =1; i <= n; i++){
        for (int j=1; j<= Wmax; j++ )
        {
            F[i][j] = F[i-1][j]; // gan cho F[i][j] gia tri truoc do de kiem tra truoc khi cap nhap
            if((F[i][j] < F[i-1][j-w[i]] + v[i]) && j>=w[i]){ //neu gia tri truoc nho hon gia tri dc chon va j >=w[i] thi cap nhat nhat gia tri moi
                F[i][j] = F[i-1][j-w[i]] + v[i];
            }
        }
    }
}

int main(){
    inputData();
    resolve();
    printRes();

}