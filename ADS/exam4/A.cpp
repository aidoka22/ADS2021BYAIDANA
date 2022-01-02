#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<vector<int>> BFS(const vector<vector<int>>& a){
    int n = a.size();
    vector<bool> boollean(n, false);
    vector<vector<int>> v1;
    for (int i = 0; i < n; ++i) {
        if (boollean[i] == false) {
            boollean[i] = true;
            vector<int> v2;
            v2.push_back(i);
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int i = 0; i < a[x].size(); ++i) {
                    int c = a[x][i];
                    if (boollean[c]) {
                        continue;
                    }
                    boollean[c] = true;
                    q.push(c);
                    v2.push_back(c);
                }
            }
            v1.push_back(v2);
        }
    }
    return v1;
}
 
int main()
{
    int n, m,mini=10000000;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<vector<int>> v3 = BFS(a);
    for(int i = 0; i < v3.size(); i++){
        if(v3[i].size() < mini)
          mini = v3[i].size();
    }
    cout << mini;
    return 0;
}