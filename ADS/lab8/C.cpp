#include <iostream>
#include<vector>
using namespace std;
void DFS(int cur, vector<vector<int> > & adj, vector<bool> & was, int & count){
    if(!was[cur]){
        was[cur] = true;
        count++;
        for(int i = 0; i < adj[cur].size(); i++){
            DFS(adj[cur][i], adj, was, count);
        }
    }
}

int Count(int start, vector<vector<int> > & adj){
    vector<bool> was(adj.size(), false);
    int count = 0;
    DFS(start, adj, was, count);
    return count;
}
int main() {
    int n;
    cin >> n;
    int start;
    cin >> start;
    start--;
    vector< vector<int> > adj(n, vector<int>());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                adj[i].push_back(j);
            }
        }
    }
    cout << Count(start, adj);
    return 0;
}