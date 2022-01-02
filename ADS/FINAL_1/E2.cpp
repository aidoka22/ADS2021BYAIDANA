#include <bits/stdc++.h> 
using namespace std;
int main(){
    deque<int> a;
    int  n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a.push_back(x);
    }
    while(a.size()!=1){
        sort(a.begin(),a.end(),greater<int>());
        int k=a[0],l=a[1];
        a.pop_front();
        a.pop_front();
        if(k!=l){
           a.push_back(k-l);
        }    
    }
    cout<<a[0];
}