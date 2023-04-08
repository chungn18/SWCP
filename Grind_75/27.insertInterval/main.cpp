#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > Array;

void InputV(){
    int m, n;
    cout << "Input graph in array\n";
    cout << "Input number of row (r) and number of collum of gapth\n";
    cin >> m >> n;
    vector<int> vecTemp;
    for (int i=0; i<m; i++){
        vecTemp.clear();
        for (int j =0; j<n; j++){
            int temp;
            cin >> temp;
            vecTemp.push_back(temp);
        }
        Array.push_back(vecTemp);
    }
}

void printGraph(vector<vector<int> > &graph)
{
    for(auto i:graph){
        for (auto j:i)
            cout << j << " ";
        cout << endl;
    }
}

int loopVertical(vector<vector<int> >& mat, int i, int j, int count){
    int res = 0;
    if(i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size()){
        return count;
    }
    if (mat[i][j] == 0) return count;
    
    return loopVertical(mat,i,j-1,count++);
    return loopVertical(mat,i+1,j,count++);
    return loopVertical(mat,i,j+1,count++);
    return loopVertical(mat,i-1,j,count++);
}
    
vector<vector<int> > updateMatrix(vector<vector<int> >& mat) {
    vector<vector<int> > res = mat;
    for (int i = 0; i <mat.size(); i++)
        for(int j = 0; j <mat[0].size(); j++){
            res[i][j] = loopVertical(mat,i,j,0);
        }
    return res;
}

int main(int arg, char* argv[]){
    vector<vector<int> > res;
    InputV();
    cout << "\n----------- INPUT --------------" << endl;
    printGraph(Array);
    res = updateMatrix(Array);
    cout << "\n----------- OUTPUT --------------" << endl;
    printGraph(res);
    return 1;
}