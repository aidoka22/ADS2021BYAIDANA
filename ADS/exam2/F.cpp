#include <iostream>
#include <vector>
using namespace std;
void quicksort(vector<int> &v, int l, int r) {
    int i, j, mid, piv;
    i = l;
    j = r;
    mid = l + (r - l) / 2;
    piv = v[mid];
    while (i<j) {
        while (v[i] < piv)
            i++;
        while (v[j] > piv)
            j--;
        if (i <= j) {
            swap(v[i],v[j]); 
            i++;
            j--;
        }
        else {
            if (i<r)
                quicksort(v, i, r);
            if (l < j)
                quicksort(v, l, j);
            return;
        }
    }
}
void bst(int l, int r,vector<int> &a) {
    int m = (l + r) / 2;
    cout << a[m] << ' ';
    if (l == r) return;
    bst(l, m - 1,a);
    bst(m + 1, r,a);
}
int main()
{
    vector<int> a;
    int n; 
    cin >> n;
    int x;
    int size = 1;
    if(n==0){
        size=1;
    }
    else{
        for(int i = 0; i < n; ++i) {
            size = size*2;
        }
    }
    size--;
    for(int i = 0; i < size; ++i) {
        cin>>x;
        a.push_back(x);
    }
    quicksort(a,0,n-1);
    bst(0, n-1,a);
}