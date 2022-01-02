#include<iostream>
#include<stdio.h>
#include<queue>
 
using namespace std;
 
int main(){
    int a,b;
    queue<int> d,d1;
    for(int i=0;i<5;i++){
        cin>>a;
        d.push(a);
    }
    for(int i=0;i<5;i++){
        cin>>b;
        d1.push(b);
    }
    int n=0;
    while(!d.empty() && !d1.empty()){
        int x=d.front();
        int y=d1.front();
        d.pop();
        d1.pop();
        if((x==0 && y==9))   {
            d.push(x);
            d.push(y);
        }
        else if(x==9 && y==0){
            d1.push(x);
            d1.push(y);
        }
        else{
            
            if(x>y){
                d.push(x);
                d.push(y);
            }
            else{
                d1.push(x);
                d1.push(y);
            }   
           }
            n++;  }
    
    if(d.empty()){
        cout<<"Nursik "<<n;
    }
    else
        cout<<"Boris "<<n;
    return 0;
}