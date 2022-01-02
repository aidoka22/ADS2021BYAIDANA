#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int l,r,cnt=0;
        cin>>l>>r;
        for(int j=l-1;j<r-1;j++){
            if(a[j]>a[j+1]){
                cnt++;
            }
        }
        cout<<cnt<<" ";
    }

}