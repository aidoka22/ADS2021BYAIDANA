#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define pb push_back

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)

#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MID = 1e5 + 3;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
#define PI 3.14159265358979323846264338327950L
  
int main(){
    speed;
    int n;
    cin >> n;
    int cnt = 0;
    vi m(n + 1, 0);
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; ++j){
            if(i * j <= n){
                m[i * j]++;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(m[i] == 1){
            cnt++;
        }
    }
    cout << cnt;   
}