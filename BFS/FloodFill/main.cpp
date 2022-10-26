#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

void Input(int V, vector<vector<int> >& Array){
    cout << "Input graph in array:\n";
    cin >> V;
    vector<int> vecTemp;
    for (int i=0; i<V; i++){
        vecTemp.clear();
        for (int j =0; j<V; j++){
            int temp;
            cin >> temp;
            vecTemp.push_back(temp);
        }
        Array.push_back(vecTemp);
    }
}

void printArray(vector<vector<int> >& arr )
{
    cout << "--------------OUTPUT--------------\n";
    for(vector<int> i:arr){
        for (int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int targetColor;
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int color) {
        targetColor = image[sr][sc];
        floodFilln(image, sr, sc, color);
        return image;
    }
private:
        
    void floodFilln(vector<vector<int> >& image, int sr, int sc, int color){
        int c = image[0].size();
        int r = image.size();
        int deltaC[4] = {-1,0,1,0};
        int deltaR[4] = {0,1,0,-1};

        if(sr >= r || sr  < 0) return;
        if(sc >= c || sc  < 0) return;
        if (image[sr][sc] == targetColor) image[sr][sc] = color;
        else return;
        for (int i=0; i<4; i++){
            floodFilln(image, sr + deltaR[i], sc + deltaC[i], color);
        }
        return;
}
};

int main(){
    vector<vector<int> > Array;
    Input(3, Array);
    Solution try1;
    try1.floodFill(Array, 1, 1, 2);
    printArray(Array);
}
/*graph to test
8
0 1 1 0 0 0 0 0
1 0 1 1 0 0 0 0
1 1 0 0 1 0 0 0
0 1 0 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 0
*/