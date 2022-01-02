#include <iostream>
using namespace std;
int main() {
	int x, i, j;
	cin >> x;
	int count = 0;
	int **a = new int*[x];
	int *b = new int[x];
	for (int i = 0; i < x; i++) {
		a[i] = new int[x];
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < x; i++) {
		cin >> b[i];
	}

	for (i = 0; i < x; i++) {
		for (j = i + 1; j < x; j++) {
			if (a[i][j] == 1) {
				if (b[i] != b[j]) {
					count++;
				}
			}
		}
	}
	cout << count;
}