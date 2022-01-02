#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        if(v.size()==0){
        v.push_back(k);}
        else{
            if(v[i]!=k){
                v.push_back(k);
            }
        }   
    }
    int max=0;
    for (int i = 0; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    int max2=0;
    for (int i = 0; i < n; i++) {
        if(v[i]!=max){
        if (v[i] > max2) {
            max2 = v[i];
        }}
    }
    cout<<max2;
}