#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[100000000];
int main() {
    int n,cnt=0;
    long long x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[x]++;
    }
    for(int i=0;i<100000000;i++){
        if(arr[i]>=3)cnt++;
    } 
    cout<<cnt;
}