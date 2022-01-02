#include <bits/stdc++.h>
using namespace std;
const int lim = 1e9;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main(){
	int n, m;
	cin >> n >> m;
	int d[n + 1][m + 1], a[n + 1][m + 1];
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m;j++) {
			cin >> a[i][j];
		d[i][j] = lim;
		if (a[i][j] == 1) {
			q.push({i, j});
			d[i][j] = 0;
		}

		}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tox = dx[i] + x;
			int toy = dy[i] + y;
			if (toy >= 1  && toy <= m && tox >= 1 && tox <= n && d[tox][toy] > d[x][y] + 1) {
				d[tox][toy] = d[x][y] + 1;
				q.push(make_pair(tox, toy));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) 
			cout << d[i][j] << " ";
		cout << endl;
	}

}