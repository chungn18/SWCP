// problem: https://leetcode.com/problems/flood-fill/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 50;
vector<vector<int>> num(N,vector<int>(N,0));
int row_len, col_len, sr, sc, color, value;
int deltaX[4] = { -1, 0, 0, 1};
int deltaY[4] = { 0, -1, 1, 0};

void inVec(){
    unsigned int N;
    cout << "Format for input...\n";
    cout << "Demention of input array: row_len col_len\n";
    cout << "Value of elements of array \n";
    cout << "Coordinate of starting point: row collum \n";
    cout << "Color \n";
    cin >> row_len >> col_len;
    vector<int> p;
    int a;
    for (int i=0; i < row_len; i++){
        for (int j=0; j < col_len; j++){
            cin >> num[i][j];
        }
    }
    cin >> sr >> sc;
    cin >> color;
}

void floodFillChild(vector<vector<int>>& image, int sr, int sc, int color) {

    if (sr < 0 || sr >= row_len || sc <0 || sc >= col_len)  return;
    if (image[sr][sc] != value) return;
    image[sr][sc] = color;
    floodFillChild(image,sr-1,sc,color);
    floodFillChild(image,sr,sc-1,color);
    floodFillChild(image,sr,sc+1,color);
    floodFillChild(image,sr+1,sc,color);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    floodFillChild(image,sr,sc,color);
    return image;
}

int main(){
    inVec();
    sr = 0;
    sc = 0;
    value = num[sr][sc];
    color = 2;
    floodFill (num,sr,sc,color);
    cout << "Output: " << endl;
    for (int i = 0; i < row_len; i++) {
        for (int j = 0; j < col_len; j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}