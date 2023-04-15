
#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26,0);
    for(auto c:tasks){
        freq[c-'A']++;
    }
    sort(freq.begin(),freq.end(),greater<int>());
    int unique_num = 0;
    for (auto counts:freq){
        if (counts >0) unique_num++;
        else break;
        //if (counts == freq[0]) unique_num++;
    }
    cout << "unique_num: " << unique_num << endl;
    int idle_max = (freq[0]-1)*n;
    int idle = idle_max;
    for (int i = 1; i < freq.size() && freq[i]>0; i++){
        if (freq[i] == freq[0])
            idle -= min(freq[i]-1,idle_max);
        else idle -= min(freq[i],idle_max);
        cout << "idle: " << idle << endl;
    }
    return idle > 0 ? idle+tasks.size():tasks.size();
}

int main(int arg, char* argv[]){
    vector<char> tasks = {'A','A','B','B'};
    cout << "Result: \n";
    cout << leastInterval(tasks,2);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"