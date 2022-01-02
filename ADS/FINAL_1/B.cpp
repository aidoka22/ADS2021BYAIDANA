#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 800;
int n;
int h;
int a[N];
int get(int x, int y) {
   return (x + y) / 2;
}
bool is_good(int c) {
   int res = 0;
   for (int i = 0; i < n; i++) res + = (a[i] + c - 1) / c;
   return res <= h;
}
void binpoisk(int l, int r) {
  int min_ans = 1e9;
   while (l <= r) {
      int centroid = get(l, r); 
      int ok = is_good(centroid);
      if (ok) {
        min_ans = centroid;
        r = centroid - 1;
      }
      else {
        l = centroid + 1;
      }
   }
   cout << min_ans, exit(0);
}
void solve() {
   cin >> n;
   cin >> h;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   binpoisk(1, 1e9);
}
int main (){
  solve();
}