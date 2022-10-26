#include <iostream>
#include <cstring>

using namespace std;
int T= 0;
int N[20], D[20];
int W[20][31];

void Input(){
    cout << "Input you string follow guide" <<endl;
    cout << "The first line is number of test cases -> T" << endl;
    cout << "Each case consists 2 lines" << endl;
    cout << "The first one contains 2 int N and D"<< endl;
    cout << "The second line contains n int representing the weight of all items" << endl;
    memset(N,0,20);
    memset(D,0,20);
    cin >> T;
    for (int j=0; j<T; j++){
        cin >> N[j] >> D[j];
        for (int i=0; i < N[j]; i++){
            cin >> W[j][i];
        }
    }
}

void solve(int n, int d, int* w) {
    int sol =0, sum =0, numSol =0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<= n-i; j++){
            sum =0;
            for (int k=j; k<j+i; k++){
            sum += w[k];
            }
            if (sum == d){
                sol += 1;
                numSol = i;
            }
        }
    }
    if ( sol ==1){
        cout << numSol <<endl;
    }
    else if (sol ==0)
        cout << "IMPOSSIBLE" <<endl;
    else 
        cout << "AMBIGIOUS" << endl;
}

int main(){
    Input();
    cout << "\n-----------OUTPUT--------------" << endl;
    for (int i=0; i<T; i++){
        cout << "Case# " << i << ": ";
        solve(N[i], D[i], W[i]);
        cout << endl;
    }
}