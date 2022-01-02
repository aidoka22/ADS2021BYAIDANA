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
int func(string s,string t){
    int n = s.length();
    int m = t.length();
    pw[0] = 1;
    pw[1] = p;
    for (int i = 2; i <= n; i++) {
        pw[i] = pw[i-1] * p;
    }
    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i-1] + (s[i-1] - 'a' + 1) * pw[i-1];
    }
    int T = 0;
    for (int i = 0; i < m; i++) {
        T = T + (t[i] - 'a' + 1) * pw[i];
    }
    int cnt = 0;
    for (int i = 0; i <= n - m; i++) {
        int hash_s = h[i + m] - h[i];
        int hash_t = T * pw[i];
        if (hash_s == hash_t) {
            cnt++;
        }
    }
    return cnt;
}
void f(string s,string t,int l,int j){
    int i=1;
    if (t==s.substr(l-j-3,l-3)){
        cout<<t;
        return;
    }
    else{
        t=t+s[i];
        cout<<t<<" ";
        i++;
        f(s,t,l,j);
    }

}
int main(){
    string s;
    cin>>s;
    string t="";
    t=t+s[0];
    if(func(s,t)<3){
        cout<<"Just a legend";
    }
    else{    
        f(s,t,s.size(),t.size());
    }

}