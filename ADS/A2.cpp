#include <iostream>

#include <cstring>

#include <stack>

using namespace std;

int s[100];
int n;
int h; 
void push(int x) {
	s[h] = x; // s[h++] = x;
	h++;
}
int main(){
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        push(k);
    }
    int g;
    cin>>g;
    for(int i=0;i<n;i++){
        if(s[i]==g){
            cout<<i+1<<" ";
        }
    }
    return 0;
}