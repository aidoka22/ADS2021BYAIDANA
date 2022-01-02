#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int g[N][30], timer = 2;
vector<int> all[N], ans[N];
void update(string s, int i) {
 	int x = 1;
 	for (int i = 0; i < s.size(); i++)
 		if (g[x][s[i] - 'a'] == 0) g[x][s[i] - 'a'] = timer++, x = timer - 1;
 		else x = g[x][s[i] - 'a'];
 	all[x].push_back(i);
}
void go (int pos, string& s) {
	int x = 1;
	for (int i = pos; i < s.size(); i++) {
		for (int to : all[x])
			ans[to].push_back(pos + 1);
	 	if (g[x][s[i] - 'a'] == 0) return;
	 	x = g[x][s[i] - 'a'];
	}
	for (int to : all[x])
			ans[to].push_back(pos + 1);
}
int main() {
	string s;
	cin >> s;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string a;
		cin >> a;
		update(a, i);
	}
	for (int i = 1; i <= s.size(); i++)
		go(i - 1, s);
	for (int i = 1; i <= t; i++) {
		cout << ans[i].size() << " ";
		for (int to : ans[i])
			cout << to << " ";
		cout << endl;
	}

  return 0; 
}