#include <bits/stdc++.h>
using namespace std;
const int N = 300;
deque<string> s;
int main(){
    int n;
    string s1;
    cin>>s1;
    cin>>n;
    for(int i=0;i<n;i++){
        string l;
        cin>>l;
        s.push_back(l);
    }
    
    for(int i=0;i<n;i++){
        string st=s[0];
        if(st+s[i]==s1){
            cout<<"YES";
            return 0;
        }
        s.pop_front();
    }
    cout<<"NO";
}