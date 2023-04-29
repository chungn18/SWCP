#include <bits/stdc++.h>
using namespace std;

int N;//Map Size
vector<vector<int>> sheet;

int delR[4] = {-1,1,0,0};
int delC[4] = {0,0,-1,1};

struct Cell {
	int r;
	int c;
	int min_w = INT_MAX;
	Cell (int inR, int inC, int inW){
		r = inR;
		c = inC;
		min_w = inW;
	}

	bool isValid (){
		return (r >=0 && r < N && c >=0 && c <N);
	}

	Cell nexCell (int ind){
		return Cell(r+delR[ind],c+delC[ind],INT_MAX);
	}

	bool operator<(const Cell& other) const{
		return min_w > other.min_w;
	}
};

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		string temp;
		vector<int> tem_vec;
		cin >> temp;
		for (auto i:temp){
			tem_vec.push_back(i-'0');
		}
		sheet.push_back(tem_vec);
	}
}

void solve(){
	priority_queue<Cell> que;
	vector<vector<int>> visited(N,vector<int>(N,INT_MAX));
	Cell quei(0,0,0);
	que.push(quei);
	visited[0][0] = 0;
	while (!que.empty()){
		quei = que.top(); que.pop();
		cout << "r: " << quei.r << ", c:" << quei.c << ", min_w: " << quei.min_w << endl;
		for (int i = 0; i < 4; i++){
			Cell next_cell = quei.nexCell(i);
			if (next_cell.isValid()){
					next_cell.min_w = quei.min_w + sheet[next_cell.r][next_cell.c];
				if (next_cell.min_w < visited[next_cell.r][next_cell.c]){
					visited[next_cell.r][next_cell.c] = next_cell.min_w;
					que.push(next_cell);
				}
				if (next_cell.r == N-1 && next_cell.c == N-1){
					cout << next_cell.min_w << endl;
					return;
				}

			}
		}
	}
	
}
int main(){

	Input_Data();		//	Input function
	solve();

	return 0;
}
/*
3
021
453
620
*/
