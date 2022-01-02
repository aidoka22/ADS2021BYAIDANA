#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
map<string, bool> used;
map<char, int> nxt[MAX];
int whole[MAX], mx = 2, q;
int main() {
	cin >> q;
	char type;
	string s;
	int x = 1;
	for (int i = 1; i <= q; i++) {
		cin >> type >> s;
		x = 1;
		if (type == '?') {
			for (int i = 0; i < s.size(); i++) {
				x = nxt[x][s[i]];
				if (x == 0) {
					cout << 0 << "\n";
					goto here;
				}
			}
			cout << whole[x] << "\n";  
			here:;
		}
		if (type == '+') {
			used[s] = 1;
			for (int i = 0; i < s.size(); i++) {
				if (nxt[x][s[i]] == 0) {
					nxt[x][s[i]] = mx;
					x = mx;
					mx++;
				}
				else x = nxt[x][s[i]];
				whole[x]++;
			}
		}
		if (type == '-') {
			if (used[s] == 0) continue;
			used[s] = 0;
			for (int i = 0; i < s.size(); i++) {
				x = nxt[x][s[i]];
				whole[x]--;
			}
		}  
	}
	return 0;

}