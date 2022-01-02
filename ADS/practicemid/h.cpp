#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 5;
vector <int> w;

void heapify_down(int *a, int n, int v) {
    int l = 2 * v;
    int r = 2 * v + 1;
    int cand = v;
    if (l <= n && a[l] > a[cand])
        cand = l;
    if (r <= n && a[r] > a[cand]) 
        cand = r;

    swap(a[v], a[cand]);
    
    if (cand != v)
        heapify_down(a, n, cand);

}


void build_heap(int *a, int n) {
    for (int i = n / 2; i >= 1; i--)
        heapify_down(a, n, i);
}

void extMax(int *a, int &n) {
    while(n!=0){
        int mx = a[1];
        swap(a[1], a[n]);
        n--;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}

int b[N], m;
 
int main() {
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++){
        w.push_back(b[i]);
    }
    
    build_heap(b, m);
    for (int i = 1; i <= m; i++){
        cout << b[i] << " ";
    }
    cout << endl; 
    extMax(b, m);
    cout<<"\n";
    sort(w.begin(), w.end());
    for(int i = 1; i <= m; i++){
        cout << w[i] << " ";
    }
    return 0;
}