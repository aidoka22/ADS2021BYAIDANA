#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
vector<int> a[N]; 
bool used[N];
vector<int> v1;
int n,m;
void topological_sort(int v){
    used[v]=1;
    for(int i=0;i<(int)a[v].size();++i){
        if(!used[a[v][i]])topological_sort(a[v][i]);
    }
    v1.push_back (v);
}
int main() {
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    for(int i=1;i<=n;++i){
        if(!used[i])topological_sort(i);
    }
    reverse(v1.begin(), v1.end());
    for(int i=0;i<(int)v1.size();++i){
        cout<<v1[i]<<' ';
    }
}