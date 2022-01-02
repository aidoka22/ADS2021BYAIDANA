#include <bits/stdc++.h>

using namespace std;

int m,edges=0,comp=0,a[111][111],n,c[111],ans=0,x,y,z;

void dfs(int v){
    for(int i=1;i<=n;i++){
        if(a[v][i]==1)
            if(c[i]==c[v]){
                cout<<"NO";
                exit(0);
            }
        if(a[v][i]==1&&!c[i]){
            if(!c[i]){
                if(c[v]==1)
                    c[i]=2;
                else
                    c[i]=1;
            }
            dfs(i);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i=1;i<=n;i++){
        if(!c[i]){
            c[i]=1;
            dfs(i);
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        if(c[i]<=1){
            cout<<i<<" ";
        }
    }
}