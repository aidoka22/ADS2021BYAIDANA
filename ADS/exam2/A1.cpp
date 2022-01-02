#include <iostream>
#include <vector>
using namespace std;
vector<int> v; 
int size=0;
long long sum=0;
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
    void heapify(int i) {
        int temp = i;
        while(true) {
            if (left(temp) > size - 1)
                return;
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
    }
    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        size++;
        siftUp(i);
    }
    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }
    void output(){
        sum += a[0]; 
        a[0] -= 1; 
        heapify(0);
    }

};

int main() {
    MaxHeap *heap = new MaxHeap();
    int  l,n;
    int y,g,k;
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        heap->insert(x);
    }
    for(int i = 0; i < k; i++){ 
        heap->output();
    } 
    cout << sum << endl; 
    return 0;
}