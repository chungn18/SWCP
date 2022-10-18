#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
int n= 0;
struct cor {
    int x;
    int y;
};

bool compareX(cor i, cor j){
    return (i.x<j.x);
}

bool compareY(cor i, cor j){
    return (i.y<j.y);
}

vector <cor> Array;

void Input(){
    cout << "Input your array" <<endl;
    cout << "The first line is number of points" << endl;
    cout << "The nth line contains coordinate of element nth (X Y)" << endl;
    cin >> n;
    for (int i=0; i<n; i++){
    cor input;
    cin >> input.x >> input.y;
    Array.push_back(input);
    }
}
float dis (cor i, cor j){
    return sqrt(pow(j.x - i.x,2)+ pow(j.y-i.y,2));
}

void printArr(vector<cor> arr)
{
    int len = arr.size();
    for (int i=0; i< len; i++){
        cout << "(" << arr[i].x << "," << arr[i].y << ")";
    }
    cout << endl;
}

float bruceForce(vector<cor> arr, int n){
    float minDis = numeric_limits<float>::max();
    for (int i=0; i<=n; i++)
        for (int j=i+1; j<=n; j++){
            if (minDis > dis(arr[i],arr[j]))
                minDis = dis(arr[i], arr[j]);
        }
    return minDis;
}

float minDisY(const vector<cor> arr, float dx){
    float dy = numeric_limits<float>::max();
    int size = arr.size();
    for (int i=0; i<size; i++){
        for (int j=i; j<size; j++){
            if ((dy > dis(arr[i], arr[j])) && (abs(arr[i].y-arr[size].y) <= dx)){
                dy = dis(arr[i], arr[j]);
            }
        }
    }
    return dy;
}
float minDis(vector<cor> arr, int l, int r)
{
    int m = (l+r)/2;
    if (r-l <=3){
        return bruceForce(arr,m);
    }
    
    float dx = min(minDis(arr,l,m),minDis(arr,m+1,r));
    int n = r-l;
    vector<cor> minArrX;
    for (int i=0; i <= n; i++){
        if (abs(arr[i].x-arr[m].x) <= dx){
            minArrX.push_back(arr[i]);
        }
    }
    return min(dx,minDisY(arr,dx));
}

int main(){
    Input();
    vector<cor> sortArrX = Array; //initialize an array to save Array of sort by x coordinate      
    sort (sortArrX.begin(), sortArrX.end(),compareX);
    float dmin = minDis(sortArrX,0,sortArrX.size()-1);
    cout <<"--------------OUTPUT------------" << endl;
    cout <<"Min distance is: " << dmin << endl;
}