#include <iostream>
#include <stack>
using namespace std;
void solve(string &s){
   stack<char> cur;
   for(int i = 0; i < s.size(); i++){
       if(!cur.empty() && ((cur.top() == '(' && s[i] == ')') || (cur.top() == '{' && s[i] == '}') || (cur.top() == '[' && s[i] == ']')))
           cur.pop();
       else cur.push(s[i]);
   }
   if(cur.empty()) cout << "yes";
   else cout << "no";
}
signed main() {
   string str;
   cin >> str;
   solve(str);
}