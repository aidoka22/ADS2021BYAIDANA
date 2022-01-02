#include <bits/stdc++.h>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
const int N = (int)1e5 + 5;
int n, v[N], tmp[N];

void merge(int *v, int n, int *w, int m, int *c) {
    int l = 1; 
    int r = 1; 
    int k = 0; 
    while (l <= n || r <= m) { 
        if (l <= n && r <= m) {
            if (v[l] <= w[r])
                tmp[++k] = v[l], l++;
            else
                tmp[++k] = w[r], r++;
            
        } else if (l > n) {
            tmp[++k] = w[r], r++;
        } else { // r > m
            tmp[++k] = v[l], l++;
        }
    }
    for (int i = 1; i <= k; i++)
        c[i] = tmp[i];
}

void merge_sort(int *v, int n) {
    if (n == 1) return;
    int m = (n + 1) / 2; 
    merge_sort(v, m);
    merge_sort(v + m, n - m);
    merge(v, m, v + m, n - m, v);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", v + i);
    }
    merge_sort(v, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", v[i]);
    puts("");
    return 0;
}
