#include<iostream>
#include<deque>
using namespace std;
int s[1000];
int n;
int h; 
deque<int> d;
void push(int x) {
	s[h] = x; // s[h++] = x;
	h++;
}
int main(){
    int n,q;
    cin>>n;
    cin>>q;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        push(k);
    }
    for(int i=0;i<q;i++){
        int l1,r1,l2,r2;
        int count=0;
        cin>>l1>>r1>>l2>>r2;
        for(int i=0;i<n;i++){
            if((l1<=s[i]&&s[i]<=r1)||(l2<=s[i]&&s[i]<=r2)){
                count++;
            } 
        }
        d.push_back(count);
        
    }
    while(!d.empty()){
        cout<<d.front()<<"\n";
        d.pop_front();
    }
}