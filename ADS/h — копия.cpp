#include <iostream>
#include <algorithm>
using namespace std;

int bin_search(int *a, int n, int k) {
	int l = 0, r = n-1;
	int x=1;
	while (l <= r) {
		int mid = (l + r) / 2; 
		for(int i=0;i<n;i++){
			if(n-a[0]>mid){
				x++;
				a[0]=i;
			}
		}
		if (k >= x)
			return true;
		if (x < a[mid])
			l=mid+1;
		else 
			r = mid ;
	}
	return l;
}
int main(){
	int n,k;
	int a[n];
	cin>>n;
	cin>>k;
    for (int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<bin_search(a,n,k);
}