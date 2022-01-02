#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
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
        while (i > 0 && a[(i-1)/2] < a[i]) {
            swap(a[(i-1)/2], a[i]);
            i = (i-1)/2;
        }
    }
    int siftDown(int i,int x){
        a[i]-=x;
        while(getMax(i)>=0){
            int max=getMax(i);
            if(a[i]<a[max]){
                swap(a[i],a[max]);
                i=max;
            }
            else break;
        }
        return i+1;
    }
    void extractMax(){
        int max=a[0];
        a[0]=a[size-1];
        size--;
        a.pop_back();
        if(size==0){
            cout<<"0 "<<max<<endl;
        }
        else{
            cout<<siftDown(0,0)<<" ";
            cout<<max<<endl;}
    }
    void insert(int k) {
        a.push_back(k);
        size++;
        int i=a.size()-1;
        siftUp(i);
        cout<<size;
    }
    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }

};

int main() {
    MaxHeap *heap = new MaxHeap();
    int  l,n,m;
    int x;
    cin >> n;
    cin>>m;
    for (int i = 0; i < m; i++) {
        cin>>x;
        if(x==1){
            if(size==0){
                cout<<"-1"<<"\n";
            }
            else{
                heap->extractMax();}
        }
        else if(x==2){
            cin>>l;
            if(size<n){
                heap->insert(l);
                cout<<"\n";}
            else{
                cout<<"-1"<<"\n";
            }
        }
    }
    heap->print();
    return 0;
}