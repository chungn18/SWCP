#include <bits/stdc++.h>
using namespace std;
int N, M;

unordered_map<string,int> cmap;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		string temp;
		cin >> temp;
		cmap.emplace(temp,0);
	}
	cin >> M;
	for (int i = 0; i <M; i++){
		string str_tem;
		int score;
		cin >> str_tem >> score;
		if (cmap.find(str_tem) != cmap.end()){
			cmap[str_tem] += score;
		}
	}
	
	pair<string,int> one({"",0}), two({"",0}), three({"",0});

	for (auto it = cmap.begin(); it != cmap.end(); it++){
		if (one.second <= it->second){
			three = two;
			two = one;
			one = make_pair(it->first,it->second);

		}
		else if (two.second <= it->second){
			three = two;
			two = make_pair(it->first,it->second);
		}
		else if (three.second <= it->second){
			three = make_pair(it->first,it->second);
		}
	}
	
	cout << one.first << " " << one.second << endl;
	cout << two.first << " " << two.second << endl;
	cout << three.first << " " << three.second << endl;
	return 0;
}