#include <iostream>
using namespace std;


int n;
int h; 

int main(){
    int n,x;
    cin>>n;
    int max=-1000000000;
    for(int i=0;i<n;i++){
        cin >> x;
        if (x > max) {
           max = x;
        }
    }    
    cout<<max;
    return 0;
}