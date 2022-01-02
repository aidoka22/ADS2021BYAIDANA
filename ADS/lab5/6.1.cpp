#include <iostream>
#include <vector>
using namespace std;
vector<int> v; 
class MaxHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMax() {
        return a[0];
    }

    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
    void siftUp2(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);    
        }
        v.push_back(i);
    }
    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }
    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }

    void increaseKey(int i, int new_value) {
        a[i] = a[i]+new_value;
        siftUp2(i);
    }

};

int main() {
    MaxHeap *heap = new MaxHeap();
    int  l,n;
    int y,g,k=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        heap->insert(x);
    }
    heap->print();
    return 0;
}