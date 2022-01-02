#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<algorithm>
#define ll int
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<int>
#define pii pair<int, int>
#define pll pair<int, int>
#define endl "\n"
const int N = (int)1e5 + 5;
const int p = 31;
int n;
int pw[N], h[N];
using namespace std;
int KMP(string s,string t){
    int m = s.size();
	s = s + '#' + t;
	int n = (int) s.length();
	vector<int> pi (n, 0);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	int l = 0;
	for(int i = 0; i < n; ++i){
		if(pi[i] == m){
			l++;
		}
	}
    return l;
}
int main(){
	string s, t;
	int k;
	cin >> s >> k >> t;
	int l=KMP(s,t);
	if(l >= k){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
}