#include <iostream>
#include <stack>
using namespace std;
void solve(string &s){
   stack<char> cur;
   for(int i = 0; i < s.size(); i++){
       if(!cur.empty() && ((s[i] == cur.top()) ))
           cur.pop();
       else cur.push(s[i]);
   }
   if(cur.empty()) cout << "YES";
   else cout << "NO";
}
signed main() {
   string str;
   cin >> str;
   solve(str);
}