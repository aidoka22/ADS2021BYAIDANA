#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    bool b=true;
    cin>>s;
    deque<pair<int, int>> q;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j] ){
                q.push_back({i,j});
            }
        }
    }
    while(q.size()!=0){
        int x=q.front().first;
        int y=q.front().second;
        q.pop_front();
        if(x==q.front().first | x==q.front().second | y==q.front().first | y==q.front().second){
            cout<<"NO";
            return 0;
        }
        if(x<=q.front().first &&  q.front().first <= y && y<=q.front().second){
            cout<<"NO";
            return 0;
        }
        cout<<"YES";
        return 0;
    }
}