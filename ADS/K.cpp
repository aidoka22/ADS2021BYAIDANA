#include <stdio.h>
 
int main (void)
{
    long long n;          
    long long i;          
    long long s = 2;      
 
    
    scanf("%d", &n);
   
 
    if (n < 2)  
    {
        s = 0;
    }
    else
    {
        for (i=2; i*i <= n; i++)
        {
            if (n%i == 0)
            {
                s = 0;  
                break;
            }
        }
    }
    if (s > 0) printf("prime");
    else printf("composite");
    return 0;
}