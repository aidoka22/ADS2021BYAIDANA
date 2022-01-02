#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
const int N = (int)1e2 + 5;
const int inf = (int)1e6;
int n, m;
vector<int> g[N]; // array of vectors, vector g[v] is adjacency list of v
int a[N][N];
int d[N], p[N]; // array of shortest distances

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    int s,f;
    queue<int> q;
    cin>>s>>f;
    s--;
    f--;
    for (int i = 0; i < n; i++)
        d[i] = inf, p[i] = -1;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for(int j=0;j<n;++j){
            if(a[v][j]&&d[j]>d[v]+1){
                d[j]=d[v]+1;
                q.push(j);
                p[j] = v;
            }
        } 
    }
    if(d[f] < inf){
        cout << d[f] << "\n";
        if (f == s) return 0;
        vector<int>ans;
        while (f != -1) {
           ans.pb(f);
           f = p[f];
        }
        reverse(ans.begin(), ans.end());
        for (int to : ans) cout << to + 1 << " ";
    }
    else{
        cout<<"-1";
    }

    return 0;
}