#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int N = (int)1e5 + 5;
const int inf = (int)1e9;
stack <int> st;
int n, m,was[N],cnt=0;
vector <int> g[N]; 
void dfs(int v, int pr=-1) {
    was[v] = 1;
    st.push(v);
    for (int u : g[v]) {
        if (u == pr) continue;
        if (was[u] == 0){
            dfs(u, v);
            cnt++;
        }
        else if (was[u] == 1) {
            vector<int> cyc;
            while (st.top() != u) {
                cyc.push_back(st.top());
                st.pop();
            }
            cyc.push_back(u);
            for (int i = 0; i < cyc.size(); i++)
                cout << cyc[i] << ' ';
            cout << "\n";
            exit(0);
        }
    }
    was[v] = 2;
    st.pop();
}
int main (){
    int n,m;
	cin >> n >> m;
    g[n].push_back(n);
    g[m].push_back(m);
    while(n!=m){
        dfs(1);
    }
    cout<<cnt;   
}