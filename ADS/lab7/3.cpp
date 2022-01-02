#include <bits/stdc++.h>
using namespace std;
const int N=1e6,lim = 1e9;
int mx;
int d[N],d1[N];
bool was[N];
vector<int> g[N]; 
int main(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        d[i] = lim,d1[i]=lim;
    d[1] = 0;
    queue<int> q;
    q.push(1);
    was[1]=1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (was[u]==0) {
                d[u] = d[v] + 1;
                was[u]=1;
                q.push(u);
            }
        }
    }
    for(int i = 1; i <=n; i++)
		was[i] = 0;
    d1[x] = 0;
    q.push(x);
    was[x]=1;
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        for (int u : g[y]) {
            if (d1[u] < d1[y] + 1) {
                d1[u] = d1[y] + 1;
                q.push(u);
            }
        }
    }
    for(int i = 1; i <= n; i++){
		if(d1[i] < d[i]){
			mx = max(mx , d[i]);
		}	
	}
	cout << mx * 2;
}