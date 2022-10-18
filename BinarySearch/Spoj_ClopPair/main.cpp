#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int n= 0;
float dx;
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

void printArr(vector<int> arr)
{
    int len = arr.size();
    for (int i=0; i< len; i++){
        if (i == len-1)
        cout << arr[i] << endl;
        else
        cout << arr[i] << ", ";
    }
}

float bruceForce(vector<cor> arr, int n){
    float minDis = INT_MAX;
    for (int i=0; i<=n; i++)
        for (int j=i+1; j<=n; j++){
            if (minDis > dis(arr[i],arr[j]))
                minDis = dis(arr[i], arr[j]);
        }
    return minDis;
}

float minDisX(vector<cor> arr, int l, int r)
{
    int m = (l+r)/2;
    if (r-l <=3){
        return bruceForce(arr,m);
    }
    return min(minDisX(arr,l,m),minDisX(arr,m+1,r));
}
vector<cor> collecXmin(const vector<cor> arr){
    vector<cor> arrTemp;
    int size = (arr.size()-1)/2;
    for (int i=0; i<arr.size(); i++){
        if (abs(arr[i].x-arr[size].x) <= dx){
            arrTemp.push_back(arr[i]);
        }
    }
    return arrTemp;
}
vector<cor> collecYmin(const vector<cor> arr){
    vector<cor> arrTemp;
    int size = (arr.size()-1)/2;
    for (int i=0; i<arr.size(); i++){
        if (abs(arr[i].y-arr[size].y) <= dx){
            arrTemp.push_back(arr[i]);
        }
    }
    return arrTemp;
}
int main(){
    Input();
    vector<cor> sortArrX = Array; //initialize an array to save Array of sort by x coordinate
    vector<cor> minArrX;          //intialize an array to save elements that distance to midle point by x < dx
    vector<cor> minArrXY;         //intialize an array to save elements that distance to midle point by y < dx          
    sort (sortArrX.begin(), sortArrX.end(),compareX);
    
    dx = minDisX(sortArrX,0,sortArrX.size()-1);
    minArrX = collecXmin(sortArrX);
    sort (minArrX.begin(), minArrX.end(),compareY);
    minArrXY = collecYmin(minArrX);
    float dmin = bruceForce(minArrXY, minArrXY.size()-1);

    cout <<"--------------OUTPUT------------" << endl;
    cout <<"Min distance is: " << dmin << endl;
}