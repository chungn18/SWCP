#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stack>
#include <list>
using namespace std;

bool checkCycle(int v, list<int> *adj, vector<bool>& visited, vector<bool>& recSta){
    
    if(!visited[v]){
        visited[v] = true;
        recSta[v] = true;
        list<int>::iterator itr;
        for( itr= adj[v].begin(); itr != adj[v].end(); itr++){
            if(!visited[*itr]){
                if(checkCycle(*itr,adj,visited,recSta)){
                    return true;
                }
            }
            else if (recSta[*itr])
                return true;
        }
    }
    recSta[v] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        list<int> *edg;
        edg = new list<int>[numCourses];
        vector<bool> visited(numCourses,0);
        vector<bool> recSta(numCourses,0);
        //Add vertex and edges
        for (int i = 0; i < prerequisites.size(); i++)
            edg[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        for (int i= 0; i < numCourses; i++){
            if (!visited[i] && checkCycle(i,edg,visited,recSta)) {
                delete[] edg;
                return true;
            }
        }
        delete[] edg;
        return false;
    }
int main(int arg, char* argv[]){
    int numCourses = 2;
    vector<vector<int> > prerequisites = {{1,0}};
    cout << "Result: " << endl;
    cout << canFinish(numCourses,prerequisites);
    cout << endl;
    return 1;
}

// s = "abcabcbb"
// s = "bbbbb"
// s = "pwwkew"