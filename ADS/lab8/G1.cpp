#include <bits/stdc++.h>
using namespace std;
int n, m;
int used[101][101];
bool a[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs (int x, int y) {  
  used[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || a[new_x][new_y] == 1 || used[new_x][new_y] == 1)
      continue;
    dfs (new_x, new_y);  
  }
}

int main () {
   cin >> n >> m;
   for (int i = 0; i < n; i++)
     for (int j = 0; j < m; j++) {
       char x;
       cin >> x;
       a[i][j] = x == '.';
      }
   int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
       if (a[i][j] == 0 && used[i][j] == 0) {
        cnt += 1;
        dfs(i, j);
      } 
    }
   cout << cnt;    
}