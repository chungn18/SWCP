// C++ program for the above approach

#include <iostream>
#include <vector>

using namespace std;

int n =0, m=0;
vector<vector<int> > inputVec;

void Input(){
	cout << "Take input follow syntax: \n";
	cout << "line 1: N - number of nodes, M - number of edges.\n";
	cout << "line i: x - node begin, y - node end, w - weight of edge\n";
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int x, y, w;
		vector<int> temp;
		cin >> x >> y >> w;
		temp.push_back(x);
		temp.push_back(y);
		temp.push_back(w);
		inputVec.push_back(temp);
	}
}
class Graph{
	private:
	int V;
	vector<int> parent;
	vector<int> key;
	vector<vector<int> > DSU;
	vector<int> mst.resize(V);
	public:
	Graph(int v):V(v),DSU(V,vector<int> (V,0)),parent(V,-1),key(V,INT_MAX){};
	void addEdge(vector<int> i){
		DSU[i[0]][i[1]]= i[2];
	}
	bool prime_MST(int s){
		mst.push_back(s);
		key[s] = 0;
		while (mst.size()<V){
			for(auto u:mst){
			for (int v =0; v<V; v++){
				if(key[v]>DSU[u][v] && DSU[u][v]>0){
					key[v]=DSU[u][v];
					mst.push_back(v);
					parent[v] = u;
				}
			}
			}
		}
		if (mst.size() ==V){
			cout << "path as follow:\n";
			for (auto i:mst){
				cout << i << "->";
			}
			return true;
			}
		else{
			cout << "Khong thuc hien duoc\n";
			return false;
		}
	}
	
};
int main(){
	Input();
	Graph g(n);
	for (auto e:inputVec)
		g.addEdge(e);
	g.prime_MST(0);
	return 0;
}
