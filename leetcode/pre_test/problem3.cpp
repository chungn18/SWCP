#include <bits/stdc++.h>
using namespace std;

int R, C, N, F, S;
vector<string> sheet;
vector<pair<int,int>> points(10);
vector<int> delr = {-1,-1,-1,0,1,1,1,0};
vector<int> delc = {-1,0,1,1,1,0,-1,-1};
vector<vector<int>> dis(10,vector<int>(10,INT_MAX));

bool isValid(int r, int c){
    return (r >= 0 && r < R && c >= 0 && c < C);
}

void Input(){
    cin >> R >> C >> N >> S >> F;
    for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        for (int j = 0; j < C; j++){
            if ( s[j] >= '1' && s[j] <= N + '0'){
                points[s[j]-'0'] = {i,j};
            }
        }
        sheet.push_back(s);
    }
}

void bfs (int ind){
    vector<vector<bool>> visited(R,vector<bool>(C,false));
    queue<pair<int,int>> que;
    que.push({-1,-1});
    que.push(points[ind]);
    visited[points[ind].first][points[ind].second] = true;
    int cnt = 0;
    while (!que.empty()){
 
        pair<int,int> quei = que.front(); que.pop();
        //cout << "r: " << quei.first << ",c: " << quei.second << endl;
        if (quei.first == -1 && !que.empty()){
            cnt++;
            que.push({-1,-1});
            continue;
        }

        for (int i = 0; i < 8; i++){
            int ri = quei.first + delr[i];
            int ci = quei.second + delc[i];
            if (isValid(ri,ci)){
                if (!visited[ri][ci] && sheet[ri][ci] != '#'){
                    visited[ri][ci]= true;
                    que.push({ri,ci});
                    if(sheet[ri][ci] > (ind + '0') && sheet[ri][ci] <= '9'){
                        dis[ind][sheet[ri][ci] - '0'] = cnt;
                        dis[sheet[ri][ci] - '0'][ind] = cnt;
                    }
                }
            }
        }
    }

}

int solve(){
 
    for (int i = 1; i < N; i++){
        bfs(i);
        dis[i][i] = 0;
    }
    dis[N][N] = 0;
    vector< int> nums;

    for (int i = 1; i <= N; i++){
        if (i != S && i != F){
            nums.push_back(i);
        }
    }

    int res_min = INT_MAX;
    if (N==2){
        res_min = min(res_min,dis[S][F]);
        return res_min == INT_MAX ? -1:res_min;
    }
    
    do {
        long long int check = 0;
        check += dis[S][nums[0]];
        check += dis[nums.back()][F];
        if (check >= INT_MAX) return -1;
        cout <<  S <<  " -> ";
        for (int j = 0; j <  nums.size()-1; j++){
            if (check >= INT_MAX) return -1;
            check += dis[nums[j]][nums[j+1]];
            cout <<  nums[j] <<  " -> ";
            
        }
        cout << nums.back() << " -> " << F <<  ": " <<  check <<  endl;
        if (res_min > check) res_min = check;

    }
    while (next_permutation(nums.begin(),nums.end()));
    
    return res_min == INT_MAX ? -1:res_min;
}


int main() {
    Input();
    cout << solve() << endl;
    return 0;
}
/* test case 1
4 6 4 4 3
#1..#.
#...2#
..#.#4
3.#...
*/

/* test case 2
4 6 4 1 4
#1..#.
#...2#
..#.#4
3.#...
*/

/* test case 3
3 3 2 1 2
1##
###
##2
*/
/*
1 6 2 1 2
#12.#.
*/
