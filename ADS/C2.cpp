#include <iostream>

using namespace std;

int s[1000];
int n;
int h; 

void push(int x) {
	s[h] = x; // s[h++] = x;
	h++;
}
int main(){
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        push(k);
    }
    int max=-100000000;
    for (int i = 0; i < n; i++) {
        if (s[i] > max) {
            max = s[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == max) {
            cout<<i+1;
            break;
        }
    }
    return 0;
}