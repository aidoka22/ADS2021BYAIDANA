#include <iostream>
#include <vector>
using namespace std;
string s;
vector<int> prefix_function(string a) {
    int n = a.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && a[i] != a[j]) 
            j = p[j - 1];
        if (a[i] == a[j]) 
            j++;
        p[i] = j;
    }
    return p;
}
int main() {
    cin >> s;
    vector<int> p = prefix_function (s);
    string t = "";
    int k=p.back();
    for (int i = 0; i < k; i++) t += s[i];
    for (int i = 1; i < (int) p.size () - 1; i++) {
        if (p[i] == k) {
            cout << t;
            return 0;
        }
    }
    cout << "Just a legend";
    return 0;
}