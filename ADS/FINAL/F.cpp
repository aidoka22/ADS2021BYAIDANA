#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &a) {
    vector<int> p;
    int min = 100000 ;
    int dif = 0 ;
    p.resize(a.size()+1);
    p[0] = 0;
    for(int i = 1 ; i < p.size(); i ++){
        p[i] = p[i-1]+a[i-1];
    }
    sort(p.begin(),p.end());
    for(int i = 1 ; i < p.size(); i++){
         dif = p[i]-p[i-1];
         if(dif<min)
         {
             min = dif;
         }
    }
    return min;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        v.push_back(s);
    }
    cout<<solution(v);
}