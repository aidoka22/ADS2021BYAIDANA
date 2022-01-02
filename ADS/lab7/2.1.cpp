#include<iostream>
#include<vector>
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
int main(){
    string s;
    int q;
    cin >> s;
    cin >> q;
    while(q --) {
        string t;
        cin >> t;
        vector <int> p = prefix_function(t + "#" + s);
        vector <int> v;
        for(int i = 0; i < p.size(); ++i){
            if(p[i] == t.size()) {
                v.push_back(i - 2 * t.size());
            }
        }
        cout << v.size() << ' ';
        for(int i=0;i<v.size();i++) {
            cout << v[i]+1<< ' ';
        }
        cout << '\n';
    }
}