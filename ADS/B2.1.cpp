#include<iostream>
using namespace std;
int main(){
    string s;
    int count=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]==s[i+1]){
            s.erase(s.begin()+i,s.begin()+i+2);
            count++;
        }
    }
    cout<<count<<" ";
    if(count%2!=0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}