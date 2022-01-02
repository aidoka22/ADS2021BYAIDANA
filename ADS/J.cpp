#include <iostream>
using namespace std;
int gcd(int a, int b){
    while(a > 0 && b > 0){
        
        if (a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    return a + b;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m);
    return 0;
}