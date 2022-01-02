#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
set<pair<int, int>> s;
int x[N], y[N], d[N];
int n;
vector<pair<int, int>> g[N];
int get(int i, int j)  {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void create() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int need = get(i, j);
			g[i].push_back({j, need});
			g[j].push_back({i, need});
		}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> x[i] >> y[i], d[i] = 1e9;
	}
	create();
	d[1] = 0;
	s.insert({0, 1});
	while (!s.empty()) {
		int v = s.begin() -> second;
		s.erase(s.begin());
		for (int i = 0; i < g[v].size(); i++) {
			int u = g[v][i].first;
			int need = max(g[v][i].second, d[v]);
			if (d[u] > need) {
				s.erase({d[u], u});
				s.insert({(d[u] = need), u});
			}         
		}
	}
	cout << d[n];
	return 0;
}