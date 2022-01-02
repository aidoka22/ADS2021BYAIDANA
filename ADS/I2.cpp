#include<iostream>
using namespace std;
int s1[1000000],s2[1000000];
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
int left_bin_search(int *a, int n, int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2; // floor
		if (x <= a[mid])
			r = mid;
		else // a[mid] < x
			l = mid + 1;
	}
	if (a[l] == x)
		return l+1;
	return 0;
}

// 1 2 3 4 5 6
int right_bin_search(int *a, int n, int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r + 1) / 2; // ceil
		if (a[mid] <= x)
			l = mid;
		else // x < a[mid] 
			r = mid - 1;
	}
	if (a[l] == x)
		return l+1;
	return 0;
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
        if(left_bin_search(s1, n, s2[j])!=0&& right_bin_search(s1, n, s2[j])!=0){
        cout << left_bin_search(s1, n, s2[j]) << " ";
		cout << right_bin_search(s1, n, s2[j])<<"\n";}
        else{
            cout<<0<<"\n";
        }
    }
    
}