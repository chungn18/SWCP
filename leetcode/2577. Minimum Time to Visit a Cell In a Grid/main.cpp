
#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<int> delR = {-1,1,0,0};
vector<int> delC = {0,0,-1,1};
class RC {
public:
    int r;
    int c;
    int s;
    RC (int ri, int ci, int si = 0){
        r = ri;
        c = ci;
        s = si;
    }
    bool isValid(){
        return (r>=0 && r <m && c>=0 && c <n);
    }
    RC next(int ind){
        return RC(r+delR[ind],c+delC[ind],s+1);
    }
    bool operator< (const RC& other) const{
        return (other.s < this->s);
    }
};

int minimumTime(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    priority_queue<RC> que;
    RC quei(0,0,0);
    que.push(quei);
    while (!que.empty()){
        quei = que.top(); que.pop();
        cout << "ri: " << quei.r << " ,ci: " << quei.c << " ,si: " << quei.s << endl;
        for (int i = 0; i < 4; i++){
            RC ne = quei.next(i);
            if (ne.isValid() && ne.s >= grid[ne.r][ne.c]){
                if (ne.r == m -1 && ne.c == n-1) return ne.s;
                que.push(ne);
            }
        }
    }

    return -1;
}

int main(int arg, char* argv[]){
    vector<vector<int>> grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    int res = minimumTime(grid);
    cout << "Result: \n";
    cout << res << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"