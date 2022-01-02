#include <iostream>
#include <vector>

using namespace std;
long n;
long a[10000000];
void quick_sort(int l, int r) {
    int i = l;
    int j = r;
    int pivot = a[(l + r) / 2];
    while (i < j) {
        while (a[i] > pivot) i++;
        while (a[j] < pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quick_sort(l, j);
    if (i < r)
        quick_sort(i, r);
}
int main(){
    int cnt = 0;
    long long z,y, x;
    cin >> n;
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        quick_sort(0, i);
        cnt++;
        if(cnt < 3)
          cout << -1 << endl;
        else {
            x = a[0];
            y = a[1];
            z = a[2];
            cout << x * y * z << endl;
        }
    }
    return 0;
}