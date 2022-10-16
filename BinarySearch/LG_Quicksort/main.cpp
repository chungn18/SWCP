#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int n= 0;
vector <int> arr;

void Input(){
    cout << "Input you string follow guide" <<endl;
    cout << "The first line is length of array" << endl;
    cout << "The second line contains n elements of array" << endl;
    cin >> n;
    for (int i=0; i<n; i++){
    int input;
    cin >> input;
    arr.push_back(input);
    }
}

int partition(int lo, int hi) {
    int pivot = arr[lo];
    int left = lo +1, right = hi;
    while (left < right) {
        while (arr[left] <= pivot && left <= right) ++left;
        while (arr[right] >= pivot && right >= left) --right;
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[lo], arr[right]);
    return right;
}


void quicksort(int lo, int hi) {
    if (lo < hi) {
        int p = partition(lo, hi);
        quicksort(lo, p - 1);
        quicksort(p+1, hi);
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

int main(){
    Input();
    cout << "\n-----------OUTPUT--------------" << endl;
    quicksort(0,arr.size()-1);
    printArr(arr);
}