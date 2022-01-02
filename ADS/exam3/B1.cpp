#include <iostream>
#include <vector>

using namespace std;

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

void func(string a, string b){
    int cnt = 0;
    a = b + '#' + a;
    vector<int> p = prefix_function(a);
    for (int i = 0; i < a.size(); i++)
    if (p[i] == b.size()) {
       cnt++;
    }
    cout << cnt << endl;
}

int main() {
    string a;
    int n; 
    cin >> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x,y;
        string b;
        cin >> x >> y;
        b = a.substr( x - 1, y - x + 1);
        func(a,b);
    }
    return 0;
}