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
        while(2 * i + 2 < a.size()){
            if(a[2 * i + 1] > a[i] && a[2 * i + 1] > a[2 * i + 2]) {swap(a[i], a[2 * i + 1]); i = 2 * i + 1; continue;}
            if(a[2 * i + 2] > a[i] && a[2 * i + 1] < a[2 * i + 2]) {swap(a[i], a[2 * i + 2]); i = 2 * i + 2; continue;}
            if(a[i] > a[2 * i + 1] && a[i] > a[2 * i + 2]) {return i;}}
            if(a[i] < a[a.size() - 1] && 2 * i + 2 == a.size()) {swap(a[a.size() - 1], a[i]); i = a.size() - 1;}
        return i;
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

    int decreaseKey(int i, int new_value) {
        a[i] = a[i]-new_value;
        return heapify(i);
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
        v.push_back(heap->decreaseKey(y-1,g));
    }
    for(int j=0;j<v.size();j++){
        cout<<v[j]+1<<"\n";
    }
    heap->print();
    return 0;
}