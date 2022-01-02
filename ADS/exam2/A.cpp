#include<iostream> 
 
using namespace std; 
int a[10000000], n, s, m; 
void sift_up(int x){ 
    if(x == 1 || a[x] <= a[x / 2]){ 
        m = x; 
        return; 
    } 
    swap(a[x], a[x / 2]); 
    sift_up(x / 2); 
} 
void sift_down(int x){ 
	m = x; 
	if(x * 2 <= s && a[x] < a[x * 2]) 
		m = x * 2; 
	if(x * 2 + 1 <= s && a[m] < a[x * 2 + 1]) 
		m = x * 2 + 1; 
	if(m == x) 
		return; 
	swap(a[x], a[m]); 
	sift_down(m); 
} 
void extract_node(int x){ 
    a[x] = - 1e9 - 1; 
    swap(a[x], a[s--]); 
    if(x <= s){ 
        sift_down(x); 
    }else m = 0; 
} 
void insert_node(int x){ 
    a[++s] = x; 
    sift_up(s); 
} 
int main(){ 
    int  x; 
    cin >> n >> x; 
    for(int i = 1; i <= n; i++){ 
        cin >> a[i]; 
        insert_node(a[i]); 
    } 
    long long sum = 0; 
    for(int i = 1; i <= x; i++){ 
        sum += a[1]; 
        a[1] -= 1; 
        sift_down(1); 
    } 
    cout << sum << endl; 
}