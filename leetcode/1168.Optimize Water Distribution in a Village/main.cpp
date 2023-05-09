
#include <bits/stdc++.h>
using namespace std;
int T, N[100], K[100];
vector<int> WELLS[100];
vector<vector<int>> PIPES[100];
void Input(int& n, int& k, vector<int>& wells, vector<vector<int>>& pipes){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        wells.push_back(temp);
    }
    for (int i = 0; i < k; i++){
        vector<int> vec_tem;
        for (int i=0 ; i <3; i++){
            int temp;
            cin >> temp;
            vec_tem.push_back(temp);
        }
        pipes.push_back(vec_tem);
    }
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>>& pipes) {
    
    vector<vector<pair<int,int>>> es(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> que;

    for (int i = 0; i <n; i++){
        es[0].push_back({i+1,wells[i]});
        es[i+1].push_back({0,wells[i]});
    }
    for (auto& i:pipes){
        es[i[0]].push_back({i[1],i[2]});
        es[i[1]].push_back({i[0],i[2]});
    }

    vector<bool> visited(n+1,false);
    vector<int> wei(n+1,INT_MAX);
    que.push({0,0});
    wei[0] = 0;
    while (!que.empty()){
        int w = que.top().first;
        int v = que.top().second;\
        que.pop();
        //cout << "v: " << v << ", w: " << w << endl;
        visited[v] = true;
        for (auto& i:es[v]){
           if (!visited[i.first] && wei[i.first] > i.second){
            wei[i.first] =  i.second;
            que.push({wei[i.first],i.first});
           }
        }
    }
    /*for (int i = 0; i <=n; i++){
        cout << "wei[" << i << "]: " << wei[i] << endl;
    }*/
    return accumulate(wei.begin(),wei.end(),0);

}

int main(int arg, char* argv[]){
    cin >> T;
    for (int i =0; i < T; i++)
    {
        Input(N[i],K[i],WELLS[i],PIPES[i]);
    }
    
    for (int i =0; i < T; i++)
    {
        cout << supplyWater(N[i],K[i],WELLS[i],PIPES[i]) << endl;
    }
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"