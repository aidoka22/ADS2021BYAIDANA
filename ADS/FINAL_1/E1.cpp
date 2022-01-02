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
    int getMax() {
        return a[0];
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }
    void insert(int k) {
        a.push_back(k);
        size++;
    }
    void sorted1(){
        sort(a.begin(),a.end(),greater<int>());
    }
    void print() {
        while(a.size()!=1){
            int k=a[0],l=a[1];
            if(k!=l){
               insert(k-l);
            }
            sorted1();
            a.pop_front();
            a.pop_front();
        }
        cout << a[0];
    }
};

int main() {
    MaxHeap *heap = new MaxHeap();
    int  n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        heap->insert(x);
    }
    heap->sorted1();
    heap->print();
    return 0;
}