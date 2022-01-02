#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function (string s,string t) {
	s=s+"#"+t;
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
int main() {
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> p=prefix_function(s,t+t);
    for(int i=0;i<p.size();i++){
        if(p[i]==s.size()){
            cout<<i-s.size()-t.size();
            return 0;
        }
    }
    cout<<-1;
}
