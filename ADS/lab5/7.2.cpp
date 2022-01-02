#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Heap{
    public:
    vector<int>a; 
    int size;
    int max_size;
    Heap(int mmm){
        size=0;
        max_size=mmm;
    }
    void print(){
        for(int i = 0; i <a.size(); i++){
        cout <<a[i] << " ";
    }
    }
    int pr(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return (i * 2) + 1;
    }
    int right(int i){
        return (i * 2) + 2;
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
    
    void add_without_sorting(int x){
        a.push_back(x);
        size++;
    }
    int siftUp(int i, int x){
        a[i] += x;
        while(i > 0 && a[pr(i)] < a[i]){
            swap(a[pr(i)], a[i]);
            i = pr(i);
        }
        return i+1;
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
};

int main(){
    int n, m, x,y; 
    cin >> n;
    Heap *h = new Heap(n);

    for(int i = 1; i <= n; i++){
        cin>>x;
        h -> add_without_sorting(x);
    }
    h->build_heap_2();
    h->print();
    return 0;
}