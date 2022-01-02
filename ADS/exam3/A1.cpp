#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 1e9 + 7;
int b=1LL;
int n, cnt, p = 31, h[100000], a[100000];
string s;
void func () {
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = ((((b* a[i - 1]  * p) % N) + N) % N);
        a[i] = (a[i] + N) % N;
    }
    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i <= n; i++) {
        int x = (s[i] - 'a' + 1); 
        int z = ((((b* x  * a[i]) % N) + N) % N); 
        h[i] = ((((h[i - 1] + N + z) % N) + N) % N);  
        h[i] = (h[i] + N) % N;
    }
}
int main() {
    cin >> s;
    n = (int) s.size ();
    func();
    for (int i = 1; n>=2*n; i++) {
        int l = h[i - 1];
        int r = ((((h[2*i- 1] - h[i - 1]) % N) + N) % N); 
        l = ((((b * l * a[i]) % N) + N) % N);
        if (l == r){ 
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}



