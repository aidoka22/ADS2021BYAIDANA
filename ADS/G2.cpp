#include<iostream>
using namespace std;
int s1[100000],s2[100000];
int h,l; 
void push1(int x) {
	s1[h] = x; 
	h++;
}
void push2(int x) {
	s2[l] = x; 
	l++;
}
int size(){
    return h;
}
bool bin_search(int *a, int n, int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2; // floor
		if (a[mid] == x)
			return true;
		// [oooooo a[mid] ooxo]
		if (x < a[mid])
			r = mid - 1;
		else // a[mid] < x
			l = mid + 1;
	}
	return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        push1(j);
    }
    for(int i=0;i<k;i++){
        int j;
        cin>>j;
        push2(j);
    }

    int i=0;
    for(int j=0;j<k;j++){
        cout<<(bin_search(s1, n, s2[j]) ? "YES\n" : "NO\n");
    }
    
}