#include <bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
using namespace std;
const int N = 1e5 + 8;
vector<int> g[N];
pair<int, int> d[N];
map<int, int> normal[N], rev[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		d[i] = {1e9, 0};
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
		normal[x][y] = 1;
		rev[y][x] = 1;
	}
	d[1] = {0, 0};
	set<pair<int, int>> s;
	s.insert({0, 1});
	while (!s.empty()) {
		int x = s.begin() -> sc;
		s.erase(s.begin());
		for (int to : g[x]) {
			int dist = 2, t = 1 ^ d[x].sc;
			if (d[x].sc == 0)
				if (normal[x][to] == 1) 
					dist = 1, t = d[x].sc;
			if (d[x].sc == 1)
				if (rev[x][to] == 1) 
					dist = 1, t = d[x].sc;
			if (d[x].fr + dist < d[to].fr) {
				s.erase({d[to].fr, to});
				d[to].fr = d[x].fr + dist;
				d[to].sc = t;
				s.insert({d[to].fr, to});
			}
		}
	}
	cout << d[n].fr;
}