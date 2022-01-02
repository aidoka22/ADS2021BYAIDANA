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
    int parent(int i){
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
    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
    void insert2(int x){
        if(size<max_size){
            a.push_back(x);
            size++;
            int i = size - 1;
            while(i > 0 && a[parent(i)] < a[i]){
                swap(a[parent(i)],a[i]);
                i = parent(i);
            }
            cout<<i+1<<endl;
        }else 
            cout<<"-1\n";
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
    void siftDown2(int v) {
		int l = 2 * v+1;
		int r = 2 * v + 2;
		int cand = v;
		if (l < size && a[l] > a[cand])
			cand = l;
		if (r < size && a[r] > a[cand]) 
			cand = r;

		swap(a[v], a[cand]);
		if (cand != v)
			siftDown2(cand);
	}
    void del2(int i){
        i--;
        if(a.size()!=0 && i>=0 && i<size){
            int m=a[i];
            swap(a[i],a[size-1]);
            size--;
            a.pop_back();
            siftUp(i);
            siftDown2(i);
            cout<<m<<endl;
        }
        else{
            cout<<"-1"<<endl;
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
    int n, m, x,y,l;
    int i=0; 
    cin >> n>>m;
    Heap *heap = new Heap(n);
    while(i!=m){
        cin>>x;
        if(x==1){
            heap->extractMax2();
        }
        else if(x==2){
            cin>>y;
            heap -> insert2(y);
        }
        else{
            cin>>l;
            heap->del2(l);
        }    
        i++;   
    }
    heap->print();
    return 0;
}