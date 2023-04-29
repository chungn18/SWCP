#include <bits/stdc++.h>
using namespace std;
string S,C;
void solve(){

	int cursor = S.size();
	for (auto c:C){
		//cout << "cursor: " << cursor << ", S: " << S << ", c: " << c << endl;
		if (c == 'L'){
			if (cursor > 0) cursor--;
		}
		else if (c == 'R'){
			if (cursor < S.size()) cursor++;
		}
		else if (c == 'B'){
			if (cursor > 0){
				S.erase(cursor-1,1);
				cursor--;
			}
		}
		else if (c >= 'a' && c <= 'z'){
			S.insert(cursor,1,c);
			cursor++;
		}
	}
	cout << S <<endl;
}
int main() {
	cin >> S;
	cin >> C;
	solve();
	return 0;
}