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
        v.push_back(k);
    }
    int max=0;
    for (int i = 0; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    int min=1000;
    for (int i = 0; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == max) {
            v[i] = min;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}