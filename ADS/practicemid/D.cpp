#include<iostream>
#include <cstdio>
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;
const int N = (int)1e5 + 5;
int  a[N], b[N];
int n, v[N], tmp[N];

void merge(int *v, int n, int *w, int m, int *c) {
    int l = 1; // pointer to left part
    int r = 1; // pointer to right part
    int k = 0; // pointer to common array

    while (l <= n || r <= m) { // can be replaced with for loop (1..n+m)
        if (l <= n && r <= m) {
            // comparing 2 candidates
            if (v[l] <= w[r])
                tmp[++k] = v[l], l++;
            else
                tmp[++k] = w[r], r++;
            
        } else if (l > n) {
            tmp[++k] = w[r], r++;
        } else { // r > m
            tmp[++k] = v[l], l++;
        }
    }
    for (int i = 1; i <= k; i++)
        c[i] = tmp[i];
}

void merge_sort(int *v, int n) {
    // v[1],v[2],...,v[n]
    if (n == 1) return;
    // split into 2 parts
    int m = (n + 1) / 2; // n/2 - floor of (n/2), (n+1)/2 - ceil of (n/2)
    
    // sort left part
    merge_sort(v, m);

    // sort right part
    merge_sort(v + m, n - m);
    
    // merge 2 parts
    merge(v, m, v + m, n - m, v);
}

vector<int> v1;
vector<int> v;
vector<int> v2;
void compare(int*a,int n1,int num){
    bool b=false ;
    for(int i=0;i<n1;i++){
         if(a[i]==num){
                b=true ;
                v1.push_back(a[i]);
          }
          else{
              b=false;
          }
        }
    if(b==false) {
        v.push_back(num) ;
    } 
        
}
int main(){
    int n1,n2;
    int sum=0;
    cin>>n1>>n2;
    for(int i=0;i<n1;i++){
        cin>>a[i];
        v2.push_back(a[i]);
    }
    for(int j=0;j<n2;j++){
        cin>>b[j];
    }
    for(int j=0;j<n2;j++){
        compare(a, n1, b[j]) ;
    }
    merge_sort(v1.begin(),v1.end());
    for(int k=0;k<v1.size();k++){
        cout<<v1[k]<<" ";
    }
    for(int k=0;k<v2.size();k++){
        for(int o=0;o<v1.size();o++){
            if(v2[k]==v1[o]){
                 v2.erase(v.begin()+k-1);
            }
        }
    }
    for(int k=0;k<v2.size();k++){
        cout<<v2[k]<<" ";
    }
}