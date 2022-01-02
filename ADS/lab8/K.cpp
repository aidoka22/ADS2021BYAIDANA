#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
queue<int> q;
int d[10001], p[10001];
int s, f;
void get1(int x) {
 	if (x % 10 == 1) return;
 	int y = x - 1;
 	if (d[y] > d[x] + 1) {
 	 	d[y] = d[x] + 1;
 	 	q.push(y);
 	 	p[y] = x;
 	}
}
void get2(int x) {
 	if (x / 1000 == 9) return;
 	int y = x + 1000;
 	if (d[y] > d[x] + 1) {
 	 	d[y] = d[x] + 1;
 	 	q.push(y);
 	 	p[y] = x;
 	}
}
void get3(int x) {
 	string s = to_string(x);
 	s = s + s[0];
 	s.erase(s.begin());
 	int y = stoi(s);
 	if (d[y] > d[x] + 1) {
 	 	d[y] = d[x] + 1;
 	 	q.push(y);
 	 	p[y] = x;
 	}
}
void get4(int x) {
	string s = to_string(x);
	s = s.back() + s;
	string k = "";
	for (int i = 0; i < s.size() - 1; i++) k+= s[i];
	int y = stoi(k);
 	if (d[y] > d[x] + 1) {
 	 	d[y] = d[x] + 1;
 	 	q.push(y);
 	 	p[y] = x;
 	}
}
int main() {
	cin >> s >> f;
	for (int i = 1; i <= 10000; i++) p[i] = -1, d[i] = 1e9;
	q.push(s);
	d[s] = 0;
	while (!q.empty()) {
  	int x = q.front();
  	q.pop();
  	get1(x);
  	get2(x);
  	get3(x);
  	get4(x);
  }
  vector<int> ans;
  while (f != -1) {
   	ans.pb(f);
   	f = p[f];
  }
  reverse(all(ans));
  for (int to : ans) cout << to << "\n";
  return 0; 
}