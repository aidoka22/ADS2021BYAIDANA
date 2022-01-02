#include <bits/stdc++.h>
using namespace std;
const int N = 300;
vector<int> g[N];
int was[N], cnt[N];
void dfs(int x) {
	was[x] = true;
	for (int to : g[x])
		if (was[to] == false)
			dfs(to);
}
int main (){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 3e5; i++) {
		int x, y;
		cin >> x;
	    if (x == 0) break;
	    else cin >> y;  
	    cnt[y]++;
	    g[x].push_back(y);
	    g[y].push_back(x);
	}  
	int kol = 0;
	if (cnt[k] > 0) cout << "No", exit(0);
	for (int i = 1; i <= n; i++)
		if (was[i] == false)
			dfs(i), kol++;
	if (kol > 1) cout <<"No", exit(0);
	cout << "Yes";
}