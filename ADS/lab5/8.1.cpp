#include <iostream>
#include <deque>
#include <bits/stdc++.h> 
using namespace std;
int size=0;
deque<int> v;
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

    int toMax(int i){
        int l=left(i);
        int r=right(i);
        if(l<size && r<size){
            if(a[l]>a[r])
                return l;
            else if(a[l]==a[r])
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
    int siftDown(int i, int x){
        a[i] -= x;
        while(toMax(i)!=(-1)){
            int mx=toMax(i);
            if(a[i]<a[mx]){
                swap(a[i],a[mx]);
                i=mx;
            }
            else break;
        }
        return i+1;
    }
    void siftDown2(int i){
        while(true){
            int mx=toMax(i);
            if(mx!=-1){
                if(a[i]<a[mx]){
                   int k=siftDown(i,0);
                }
                else break;
            }
            else break;
            
        }
    }
    void build_heap_2(){
        for(int i = a.size()/2; i >= 0; i--){
            siftDown2(i);
        }
    }
    void extract() {
        int root_value = a[0];  
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        size--;
    }
    void insert(int k) {
        a.push_back(k);
        size++;
    }
    void sorted1(){
        sort(a.begin(),a.end(),greater<int>());
    }
    void sorted(){
        for(int i=0;i<size;i++){
            v.push_back(a[i]);}
        sort(v.begin(),v.end());
    }
    void output(){
        while(size!=0){
            build_heap_2();
            print();
            extract();
        }
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
    heap->output();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}