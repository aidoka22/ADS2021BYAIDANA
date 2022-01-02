#include <bits/stdc++.h>

using namespace std;

int edges=0,comp=0,a[111][111],n,color[111],ans=0,u[111];

void dfs(int v){
    u[v]=1;
    for(int i=1;i<=n;i++){
        if(a[v][i]==1&&!u[i]){
            dfs(i);
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==1)
                edges++;
        }
    }
    edges/=2;
    for(int i=1;i<=n;i++){
        if(!u[i]){
            dfs(i);
            comp++;
        }
    }
    if(n-1==edges&&comp==1){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}