#include <bits/stdc++.h>
using namespace std;
int main (){
	int n;
	cin >> n;
	multiset<int> s;
	for (int i = 1; i <= n; i++) {int x; cin >> x, s.insert(-x);}
	while (s.size() > 1) {
		int x = *s.begin();
		s.erase(s.begin());
		int y = *s.begin();
		s.erase(s.begin());
		x = abs(x);
		y = abs(y);
		x -= y;
		y = 0;
		if (x != 0) s.insert(-x);
		if (y != 0) s.insert(-y); 
	}
	if (s.empty()) cout << 0, exit(0);
	cout << abs(*s.begin());
}