#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const int inf=1e9;
int d[N][N], a[N][N];
int main() {
	int n, m;
	cin >> n >> m;
	queue<int> q1, q2;
	for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> a[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = inf;
			if (a[i][j] == 1)
				d[i][j] = 0, q1.push(i), q2.push(j);
		}
	}
	while (!q1.empty()) {
		int x = q1.front();
		int y = q2.front();
		q1.pop();
		q2.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (abs(i) == abs(j)) continue;
				int dx = i + x;
				int dy = j + y;
				if (dx < 0 || dx > n || dy < 0 || dy > m || a[dx][dy] != 1 || d[dx][dy] <= d[x][y] + 1) continue;
				d[dx][dy] = d[x][y] + 1;
				q1.push(dx);
				q2.push(dy);
			}
		}  
	}  
	for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            if(d[i][j]=0){
				cout<<0<<" ";
			}
			else{
				cout<<1<<" ";
			}

}



