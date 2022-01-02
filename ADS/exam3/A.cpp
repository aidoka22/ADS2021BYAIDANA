#include <iostream>
#include<vector>
using namespace std;    
const int N = (int)1e5 + 5;
const int p = 31;
int n;
int pw[N], h[N];
int prefix_function (string s) {
	int n = (int) s.length();
	pw[0] = 1;
    for(int i = 1; i < n; ++i)
        pw[i] = pw[i - 1] * p;
    int h[n];
    h[0] = s[0] - 'a';
    for(int i = 1; i < n; ++i)
        h[i] = h[i - 1] + (s[i] - 'a') * pw[i];
    int cnt = 0;
    for(int i = 1; i < n - 1; i += 2){
        int a = (i+1)/ 2;
        int h1 = h[a - 1];
        int h2 = h[i] - h1;
        if(h1 * pw[a] == h2)
            ++cnt;
    } 
    return cnt;
}

int main () {
    string s;
    cin >> s;
    cout<<prefix_function(s);
}