#include <iostream>
#include <vector>

using namespace std;
vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) 
            j = p[j - 1];
        if (s[i] == s[j]) 
            j++;
        p[i] = j;
    }
    return p;
}
int main() {
    string s;
    int n; 
    cin >> s;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x,y,cnt=0;
        string t;
        cin >> x >> y;
        t = s.substr( x - 1, y - x + 1);
        s = t + '#' + s;
        vector<int> p = prefix_function(s);
        for (int i = 0; i < s.size(); i++)
            if (p[i] == t.size()) {
                cnt++;
            }
        cout << cnt << endl;
    }
    return 0;
}