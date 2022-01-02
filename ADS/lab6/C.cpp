#include <iostream>
#include <stdio.h>
#include <cassert>
#include <string>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = (int)1e5 + 5;
const int p = 31;
// const int mod = (int)1e9 + 7;

int n;
int pw[N], h[N]; // unisigned int

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
int main() {

    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();
    int k=n;
    while (n!=0)
        if(func(s,t)==0){
            reverse(t.begin(),t.end());
            t.pop_back();
            reverse(t.begin(),t.end());
            n--;
        }
        else if(func(s,t)==1){
            if(k-n<=0){cout<<"-1";}
            else{cout<<k-n;}
            break;
        }
        else{
            cout<<"-1";
        }
    return 0;
}