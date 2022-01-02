#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5000 + 500 + 50 +5;
int used[N];
vector<vector<int>> g(N);
void dfs(int x) {
	used[x] = true;
	for (int i = 0; i < g[x].size(); i++)
		if (used[g[x][i]] == 0) 
			dfs(g[x][i]);
}
int main() {   
	int n, m;
	cin >> n >> m;
	int i = 1;
	int a[n + 1], b[n + 1];
	while (m--) {
		cin >> a[i] >> b[i];
		g[a[i]].emplace_back(b[i]);
		g[b[i]].emplace_back(a[i]);
		i++;
	}
	int print = 0;
	for (int i = 1; i <= n; i++)
		if (used[i] == 0) print++, dfs(i);
	cout << print - 1;
	return 0;
}