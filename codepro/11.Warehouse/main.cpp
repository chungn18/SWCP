#include <bits/stdc++.h>
using namespace std;
int N, M;
int graph[100+1][100+1];

void Input(){
	cin >> N >> M;
	//adj.resize(N,pair<int,int>(2,0));
	for (int i = 1; i <= M; i++){
		int r, c, w;
		cin >> r >> c >> w;
		graph[r][c] = w;
		graph[c][r] = w;
	}
}


int minDis(vector<bool>& stp, vector<int>& dist){
	int min_dist = INT_MAX;
	int ind = 0;
	for (int v =1; v <= N; v++){
		if(stp[v] == false && min_dist > dist[v]){
			min_dist = dist[v];
			ind = v;
		}
	}

	return ind;
}

void printRes(vector<bool> & spt, vector<int>& dist){
	cout << "Vertex" << "\t" << "Distance to find\n";
	for (int i = 1; i <= N && spt[i]; i++){
		cout << i << "\t\t" << dist[i] << endl;
	}
}

int getResult(int start){
	vector<bool> stp(N+1,false);
	vector<int> dist(N+1,INT_MAX);
	dist[start] = 0;
	int res = 0;
	for (int cnt = 1; cnt <= N; cnt++){
		int u = minDis(stp,dist);
		//cout << "u: " << u << endl;
		stp[u] = true;

		for (int v = 1; v <=N; v++){
			if (!stp[v] && graph[u][v] && dist[u] != INT_MAX && graph[u][v] + dist[u] < dist[v]){
				dist[v] = graph[u][v] + dist[u];
			}
		}
		res = max(res,dist[u]);
	}
	printRes(stp,dist);
	return res;
}



int main() {
	Input();
	int ans = INT_MAX;
	for (int i = 1; i <=N; i++){
		ans = min(ans,getResult(i));
	}
	
	return 0;
}
/*
5 7
1 2 5
3 2 14
2 4 5
1 3 10
4 3 15
5 4 15
3 5 8
*/