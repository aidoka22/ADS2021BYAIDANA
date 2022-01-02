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

    int getMax(int i){
        int l=left(i);
        int r=right(i);
        if(l<size && r<size){
            if(a[l]>a[r])
                return l;
            else
                return r;
        }
        else if(l<size){
            return l;
        }
        else {
            return -1;
        }
    }
    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
    void siftDown(int i, int x){
        a[i] -= x;
        while(getMax(i)>=0){
            int max=getMax(i);
            if(a[i]<a[max]){
                swap(a[i],a[max]);
                i=max;
            }
            else break;
        }
    }
    void insert(int k) {
        a.push_back(k);
        size++;
        int i=0;
        Build_Heap2(i);
    }
    void Build_Heap2(int i){
        siftDown(i,0);
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
    heap->print();
    return 0;
}