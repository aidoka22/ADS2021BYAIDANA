#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
const int N = 105;
int n, m;
int was[N], used[N], t[N], dp[N];
vector<int> a[N], b[N], top;
vector<pair<int, int>> all;
void go_1(int x) {
 	was[x] = true;
 	for (int to : a[x])
 		if (was[to] == false)
 			go_1(to);
	top.pb(x);
}
void go_2(int x) {
 	used[x] = true;
 	for (int to : b[x])
 		if (used[to] == false)
 			go_2(to);
}
void depth (int x, int pr) {
 	dp[x] = dp[pr] + 1;
 	for (int to : a[x])
 		if (dp[x] + 1 > dp[to])
 			depth(to, x);
}
int main() {
	cin >> n >> m;
	int ok = 0;
	for (int i = 0; i < m; i++)  {
		int x, y;
		cin >> x >> y;
		t[y] = true;
		a[x].pb(y);
		b[y].pb(x);
	}
	for (int i = 1; i <= n; i++)
		if (was[i] == false)
			go_1(i);
	reverse(all(top));
	for (int to : top) {
	 	if (used[to] == false) {
	 		go_2(to);
	 		ok++;
	 	}
	}
	if (ok != n) {cout << "No"; return 0;}
	cout << "Yes\n";
	for (int i = 1; i <= n; i++) if (t[i] == false) depth(i, 0);
	for (int i = 1; i <= n; i++) all.pb({dp[i], i});
	sort(all(all));
	for (int i = 1; i <= n; i++) cout << all[i - 1].second << " ";
  return 0;
}