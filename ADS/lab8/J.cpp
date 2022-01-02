#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N = (int)1e2 + 5;
const int inf = (int)1e6;
int p1[N],p2[N];
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,2,-2,1,-1};
int main(){
	int n;
	cin>>n;
	int arr[n+1][n+1];
    queue<pair<int,int>>q;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
            arr[i][j]=inf,p1[i]=-1,p2[j]=-1;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	arr[a][b]=0; 
    q.push(make_pair(a,b));
	while(!q.empty()){
		int i,j;
		i=q.front().first;
        j=q.front().second;
        q.pop();
		for(int k=0;k<8;++k){
			int u,v;
            u=i+dx[k];
            v=j+dy[k];
			if( u>0&&u<=n&&v>0&&v<=n&&arr[u][v]>arr[i][j]+1){
				arr[u][v]=arr[i][j]+1;
                q.push(make_pair(u,v));
                p1[i]=u;
                p2[j]=v;
            }
        }
    }
    if(arr[c][d]<inf){
	    cout<<arr[c][d]<<"\n";
        if (a == d & b==c) return 0;
        vector<pair<int,int>>ans;
        while (a != -1 && b!=-1) {
           ans.pb(mp(a,b));
           a = p1[a];
           b = p2[b];
        }
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }
	return 0;
}