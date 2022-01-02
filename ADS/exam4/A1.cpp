#include <bits/stdc++.h>
using namespace std;
const int N=1e6,lim = 1e9;
int min=1e6;
int d[N],d1[N];
bool was[N];
vector<int> g[N]; 
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(was[i]==0){
            
        }
    }

}