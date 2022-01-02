#include<iostream>
#include<vector>
using namespace std;
const long long N = (long long)1e6 + 6;
const long long MOD = (int)1e9 + 7;
const long long p = 31;
long long pw[N], h[N];
void func(string s,string t){
    long long n = s.length();
    long long m = t.length();
    vector<int> v;
    pw[0] = 1;
    pw[1] = p;
    for (long long i = 2; i < max(n, m) + 1; i++) {
        pw[i] = pw[i - 1] * p%MOD;
    }
    h[0] = s[0] - 'a' + 1;
    for (long long i = 1; i < n; i++) {
        h[i] = h[i-1] + (s[i] - 'a' + 1) * pw[i];
        h[i]%=MOD;
    }
    long long T = 0;
    for (long long i = 0; i < m; i++) {
        T = T + (t[i] - 'a' + 1) * pw[i];
        T%=MOD;
    }
    long long cnt = 0;
    for (long long i = 0; i + m - 1 < n; i++) {
        long long hash_s = h[i + m-1];
        if(i>0){
            hash_s-=h[i-1];
            hash_s+=MOD;
            hash_s%=MOD;
        }
        long long hash_t = T * pw[i];
        hash_t%=MOD;
        if (hash_s == hash_t) {
            v.push_back(i+1);
        }
    }
    cout<<v.size()<<" ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    
}
int main(){
    string s1;
    cin>>s1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        func(s1,s);
    }
}