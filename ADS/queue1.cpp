#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<char> q;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(!q.empty() && s[i]=='i' && q.back()=='1'){
          q.pop();
        }else{
          q.push(s[i]);
        }  
    }
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    return 0;
}