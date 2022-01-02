#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int x = n;
	vector<int> d(10005, -1), v(10005);
	d[n] = 0;
	queue<int> q;
	q.push(n);
	while(n != m){
		n = q.front();
		q.pop();
		int a = n * 2;
		if(a > 0 && a < 2e4 + 1 && d[a] == -1){
			d[a] = d[n] + 1;
			v[a] = n;
			q.push(a);
		}
		int b = n - 1;
		if(b > 0 && b < 2e4 + 1 && d[b] == -1){
			d[b] = d[n] + 1;
			v[b] = n;
			q.push(b);
		}
	}
	cout << d[m] << "\n";
	vector<int> ans;
	while(m != x){
		ans.push_back(m);
		m = v[m];
	}
	reverse(ans.begin(), ans.end());
	for(int i : ans){
		cout << i << " ";
	}
}