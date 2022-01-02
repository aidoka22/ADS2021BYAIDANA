#include <stdio.h>
using namespace std;

long long int NOD(long long int n, long long int k){
   while(n != k){
       if(n > k)
           n = n - k;
       else k = k - n;
   }
   return n;
}

long long int NOK(long long int n, long long int k){
   return (n * k) / NOD(n, k);
}

int main(){
   long long int N, K;
   scanf("%lli%lli", &N, &K);
   printf("%lli\n", NOK(N, K));
}