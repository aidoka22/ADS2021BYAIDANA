#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int>dq;
    int n,k,i,num;
    cin>>n;
    bool t = false;
    while(n--){
        cin>>k;
        if(k==2){
            if(t){
                t=false;
            }
            else{
                t=true;
            }
        }
        else{
            cin>>num;
            if(t){
                dq.push_back(num);
            }
            else {
                dq.push_front(num);
            }
        }
    }
    while(!dq.empty()) {
        if(t){
            cout<<dq.front()<<" ";
            dq.pop_front();
        }
        else{
            cout<<dq.back()<<" ";
            dq.pop_back();
        }
    }
}