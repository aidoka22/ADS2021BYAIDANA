#include<iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    float k;
    cin>>n;
    k=log10(n-1)/log10(2);
    int c=k;
    cout<<c+1;
}