#include <iostream>
#include <deque>
#include <bits/stdc++.h> 
using namespace std;
int size=0;
class MaxHeap {
    public:
    deque<int> a;

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
    int extractMax() {
        int root_value = getMax();  
        swap(a[0], a[a.size() - 1]);
        a.pop_front();
        heapify(0);
        for(int i=0;i<size;i++){
            if(a[i]==root_value){
                cout<<i<<" ";
            }
        }
        cout<<root_value;
    }
    void insert(int k) {
        a.push_back(k);
        size++;
        int i=a.size()-1;
        heapify(i);
    }
    void sorted(){
        sort(a.begin(),a.end());
    }
    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
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
    heap->sorted();
    heap->print();
    return 0;
}