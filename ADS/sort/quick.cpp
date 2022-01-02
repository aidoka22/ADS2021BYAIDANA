#include <iostream>
#include <cassert>
using namespace std;
const int N = (int)1e5 + 5;


int partion(int *a, int n) {
	int pivot = a[n - 1];
	int i = 0;
	for (int j = 0; j < n - 1; j++) {
		if (a[j] <= pivot) {
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[n - 1]);
	return i;
}

void quick_sort(int *a, int n) {
    if (n <= 1) return;
    int p = partion(a, n);
    quick_sort(a, p);
    quick_sort(a + p + 1, n - p - 1);
}


int b[N], m;

int main() {

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    quick_sort(b + 1, m);

    for (int i = 1; i <= m; i++)
        cout << b[i] << ' ';
    cout << "\n";

        
    return 0;
}
