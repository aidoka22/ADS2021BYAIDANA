#include <iostream>
#include <vector>

using namespace std;
const int N = 1000000;
int v[N];
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
    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[left(i)] > a[right(i)])
            j = right(i);
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax() {
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }

    void increaseKey(int i, int new_value) {
        a[i] = a[i]+new_value;
        siftUp(i);
    }

    void decreaseKey(int i, int new_value) {
        a[i] = a[i]-new_value;
        siftUp(i);
    }

};

int main() {
    MaxHeap *heap = new MaxHeap();
    int  l,n;
    int y,g;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        heap->insert(x);
    }
    cin>>l;
    for(int i=0;i<l;i++){
        cin>>y>>g;
        heap->increaseKey(y-1,g);
    }
    heap->print();
    return 0;
}