#include <iostream>

using namespace std;

string a;

bool isVowel(char a) {
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return 1;
    return 0;
}

int compare(int a, int b) {
    if(isVowel(a) && isVowel(b)) {
        if(a == b)
            return 0;
        if(a > b)
            return 1;
        return -1;
    }
    if(isVowel(a))
        return -1;
    if(isVowel(b))
        return 1;

    
    if(a == b)
        return 0;
    if(a > b)
        return 1;
    return -1;
    
}

void quicksort(int l, int r) {
    int i = l;
    int j = r;
    int p = a[(l + r) / 2];
    while (i < j) {
        while (compare(a[i], p) == 1) i++;
        while (compare(a[j], p) == -1) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quicksort(l, j);
    if (i < r)
        quicksort(i, r);
}


int main () {
    int n;
    cin >> n;
    cin >> a;
    quicksort(0, a.size() - 1);
    for(int i = 0; i < n / 2; ++i)
        swap(a[i], a[n - i - 1]);
    cout << a;
}