#include <iostream>
#include <vector>
using namespace std;
vector<int> v; 
int size=0;
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
    int heapify(int i) {
        int temp = i;
        while(true) {
            if (left(temp) > size - 1)
                return temp;
            int j = left(temp);
            if (right(temp) < size && a[j] < a[right(temp)])
                j = right(temp);
            if (a[temp] < a[j]) {
                swap(a[temp], a[j]);
                temp = j;
            }
            else
                break;
        }
        return temp;
    }
    void insert(int k) {
        a.push_back(k);
        size++;
        int i = a.size()-1;
        siftUp(i);
    }
    void print() {
        for (int i = 0; i < size; i++) 
            cout << a[i] << " ";
        cout << endl;
    }

    void decreaseKey(int i, int new_value) {
        a[i] = a[i]-new_value;
        v.push_back(heapify(i));
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
        heap->decreaseKey(y-1,g);
    }
    for(int j=0;j<v.size();j++){
        cout<<v[j]+1<<"\n";
    }
    heap->print();
    return 0;
}