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
class DSU{
	int* parent;
	int* rank;
	public:
	DSU (int n){
		parent =new int [n+1];
		rank = new int[n+1];
		for (int i=0; i<=n; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	int find(int i){
		if (parent[i] == -1)
		return i;

		return parent[i]=find(parent[i]);
	}
	bool unity (int x, int y){
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2){
			if (rank[s1]<=rank[s2]){
				parent[s1] = s2;
				rank[s2] += rank[s1];
				return false;
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
				return false;
			}
		}
		else {
			return true;
		}
	}
};
class Graph {
	private:
	vector<vector<int> > edgeList;
	int V;
	public:
	Graph():V(0){};
	Graph(int v):V(v){};

	void addEdge(int x, int y, int w){
		vector<int> temp;
		temp.push_back(w);
		temp.push_back(x);
		temp.push_back(y);
		edgeList.push_back(temp);
	}
	int kruskals_mst(){
		int sumWeight =0;
		int numV = 0;
		DSU s(V);
		sort(edgeList.begin(),edgeList.end());
		for (auto e:edgeList){
			if (!s.unity(e[1],e[2])){
				sumWeight += e[0];
				numV += 1;
				cout << e[1] <<" ----------- "<< e[2] << " = " << e[0] << endl;
			}
			else {
				continue;
			}
		}
		if(numV == V-1){
			cout << "-------------weight of MST = " << sumWeight <<endl;
			return sumWeight;
		}
		else{
			cout << "Impossible to find out a MST\n";
			return 0;
		}
	}
};
int main(){
	Input();
	Graph g(n);
	for (auto e:inputVec)
		g.addEdge(e[0], e[1], e[2]);
	
	g.kruskals_mst();
	return 0;
}
