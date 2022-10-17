#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int n= 0;
vector <int> arr;

void Input(){
    cout << "Input your array" <<endl;
    cout << "The first line is length of array" << endl;
    cout << "The second line contains n elements of array" << endl;
    cin >> n;
    for (int i=0; i<n; i++){
    int input;
    cin >> input;
    arr.push_back(input);
    }
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
int maxAllArrSum(int l, int m, int r){
    int sumLMax = INT_MIN;
    int sum =0;
    for (int i=l; i<=m; i++){
        sum += arr[i];
        if (sum > sumLMax)
        sumLMax = sum;
    }

    int sumRMax = INT_MIN;
    sum =0;
    for (int i = m+1; i<=r; i++){
        sum +=arr[i];
        if (sum>sumRMax)
        sumRMax = sum;
    }
    return max(max(sumLMax,sumRMax),sumLMax+sumRMax);
}
int maxSubArrSum(int l, int r){
    if (l==r) return arr[l];
    int m = (l+r)/2;
    cout << "Value of l, m, r: " << l << " " << m << " " << r << endl;
    return (max(max(maxSubArrSum(l,m),maxSubArrSum(m+1,r)),maxAllArrSum(l,m,r)));
}


int main(){
    Input();
    cout << maxSubArrSum(0, arr.size()-1) << endl;
}