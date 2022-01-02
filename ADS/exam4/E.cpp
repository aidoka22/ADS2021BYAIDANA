#include <bits/stdc++.h>

using namespace std;

int m,a[111][111],n,c[111],cnt=0,x,y,z;

void dfs(int v){
    c[v]=0;
    for(int i=1;i<=n;i++){
        cout<<a[v][i]<<" ";
        if(a[v][i]==1)
            cnt++;
            c[i]=1;
        if(a[v][i]==0){
            cnt=cnt+2;
            if(a[v+1][i]==0 | a[v][i+1]==0)
                cnt++;
            else{
                break;
            }
            c[i]=1;
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
        a[y][x]=0;
    }
    int i=0;
    while(i!=n){
        if(!c[i]){
            c[i]=1;
            dfs(i);
        }
        i++;
    }
    cout<<cnt;
}