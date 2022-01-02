#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
int dx[] = {2, -2, -1, 1, -2, 2, -1, 1};
int dy[] = {-1, -1, -2, -2, 1, 1, 2, 2};
int dp[105][105];
pair<int, int> p[30][30];
int main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	queue<int> qx, qy;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dp[i][j] = 1e9, p[i][j] = {-1, -1};
	dp[a][b] = 0;
	qx.push(a);
	qy.push(b);
	while (!qx.empty()) {
	 	int x = qx.front();
	 	int y = qy.front();
	 	qx.pop();
	 	qy.pop();
	 	for (int i = 0; i < 8; i++) {
	 	 	int kx = x + dx[i];
	 	 	int ky = y + dy[i];
	 	 	if (min(kx, ky) <= 0 || max(kx, ky) > n || dp[kx][ky] < dp[x][y] + 1) continue;
	 	 	dp[kx][ky] = dp[x][y] + 1;
	 	 	p[kx][ky] = {x, y};
	 	 	qx.push(kx);
	 	 	qy.push(ky);
	 	}
	}
	cout << dp[c][d] << "\n";
	vector<pair<int, int>> ans;
	while (c != -1 && d != -1) {
	 	ans.pb({c, d});
	 	int x, y;
	 	make_pair(x, y) = p[c][d];
	 	c = x;
	 	d = y;
	}
	reverse(all(ans));
	for (auto to : ans)
		cout << to.first << " " << to.second << endl;
  return 0; 
}