#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl "\n"
using namespace std;

int n, k;

bool f(int m, vector<pair<pii, pii> > &a){
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(a[i].second.first > m || a[i].second.second > m)
            ++cnt;
        if(cnt > n - k) return false;
    }
    return true;
}

int main() {
    int x1, x2, x3, x4;
    cin >> n >> k;
    vector<pair<pii, pii> > a(n);
    for(int i = 0; i < n; ++i){
        cin >> x1 >> x2 >> x3 >> x4;
        a[i] = mp(mp(x1, x2), mp(x3, x4));
    }
    int l = 0;
    int r = 1e9;
    while(l + 1 < r){
        int m = (l + r) / 2;
        if(f(m, a))
            r = m;
        else
            l = m;
    }
    cout << r;
    
    return 0;
}