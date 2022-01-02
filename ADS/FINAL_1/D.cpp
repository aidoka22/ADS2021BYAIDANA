#include <iostream>
#include <stack>
using namespace std;
int solve(string &s){
   stack<char> cur;
   for(int i = 0; i < s.size(); i++){
       if(!cur.empty() && ((s[i] == cur.top()) ))
           cur.pop();
       else cur.push(s[i]);
   }
   if(cur.empty()) return 1;
   return 0;
}
signed main() {
   int n,cnt=0;
   cin>>n;
   for(int i=0;i<n;i++){
       string str;
        cin >> str;
        if(solve(str)==1){
              cnt++;
        }
   }
   cout<<cnt;
}