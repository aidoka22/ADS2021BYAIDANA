#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
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
const long long N = (long long)1e5 + 5;
const long long p = 31;
long long pw[N], h[N];
int func(string s,string t){
    long long n = s.length();
    long long m = t.length();
    pw[0] = 1;
    pw[1] = p;
    for (long long i = 2; i <= n; i++) {
        pw[i] = pw[i-1] * p;
    }
    h[0] = 0;
    for (long long i = 1; i <= n; i++) {
        h[i] = h[i-1] + (s[i-1] - 'a' + 1) * pw[i-1];
    }
    long long T = 0;
    for (long long i = 0; i < m; i++) {
        T = T + (t[i] - 'a' + 1) * pw[i];
    }
    long long cnt = 0;
    for (long long i = 0; i <= n - m; i++) {
        long long hash_s = h[i + m] - h[i];
        long long hash_t = T * pw[i];
        if (hash_s == hash_t) {
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<string, int> >  a;
    vector<int> v;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<n;i++){
        string s;
        int h,cnt=1;
        cin>>h>>s;
        a.push_back(mp(s,h));
        while(h/10!=0){
            cnt++;
            h=h/10;
        }
        v.push_back(cnt);
    }
    int maxElement = *max_element(v.begin(), v.end());
    int minElement = *min_element(v.begin(), v.end());
    for(int i=0;i<n;i++){
        int cnt2=1;
        int h=a[i].second;
        while(h/10!=0){
            cnt2++;
            h=h/10;
        }
        if(cnt2==maxElement){
            v1.push_back(i);
        }
    }
    int m=v1[0],l;
    for(int i=0;i<n;i++){
        if(i==m){
            cout<<a[i].first<<a[i].second<<"\n";
            l=a[i].second;
        }
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        
    }
}