#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

class Heap{
    public:
    vector<int>a; 
    int size;
    int max_size;
    Heap(int value){
        size=0;
        max_size=value;
    }
    void print(){
        for(int i = 0; i <a.size(); i++){
        cout <<a[i] << " ";
    }
    }
    int part(int i){
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
    void insert(int x){
        a.push_back(x);
        size++;
        int i = size - 1;
        while(i > 0 && a[part(i)] < a[i]){
            swap(a[part(i)],a[i]);
            i = part(i);
        }
    }
    void insert2(int x){
        if(size<max_size){
            a.push_back(x);
            size++;
            int i = size - 1;
            while(i > 0 && a[part(i)] < a[i]){
                swap(a[part(i)],a[i]);
                i = part(i);
            }
            cout<<i+1<<endl;
        }else 
            cout<<"-1\n";
    }
    
    int siftUp(int pos, int x){
        a[pos] += x;
        while(pos > 0 && a[part(pos)] < a[pos]){
            swap(a[part(pos)], a[pos]);
            pos = part(pos);
        }
        return pos+1;
    }

    int siftDown(int pos, int x){
        a[pos] -= x;
        bool f=true;
        while(toMax(pos)!=(-1)){
            int mx=toMax(pos);
            if(a[pos]<a[mx]){
                swap(a[pos],a[mx]);
                pos=mx;
            }
            else break;
        }
        return pos+1;
    }

    void extractMax(){
        while(size!=1){
            int mx=a[0];
            a[0]=a[size-1];
            size--;
            a.pop_back();
            cout<<siftDown(0,0)<<" ";

            cout<<mx<<endl;
        }
    }

    void extractMax2(){
        if(a.size()==0){
            cout<<"-1\n"; 
        }else if(a.size()==1){
            cout<<0<<endl<<a[0]<<endl;
            a.pop_back();
            size--;
        }else{
            int mx=a[0];
            a[0]=a[size-1];
            size--;
            a.pop_back();
            cout<<siftDown(0,0)<<" ";
            cout<<mx<<endl; 
        }
        
        
    }
};

int main(){
    int n, m, x,y; 
    cin >> n>>m;
    Heap *heap = new Heap(n);

    for(int i = 1; i <= m; i++){
        cin>>x;
        if(x==1){
            heap->extractMax2();
        }
        else{
            cin>>y;
            heap -> insert2(y);
        }
        
    }
    heap->print();
    return 0;
}