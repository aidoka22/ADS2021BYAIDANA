#include <stdio.h>
 
int main (void)
{
    int n;          
    int i;          
    int s = 2;      
 
    
    scanf("%d", &n);
    if (n > 2000000000) return -1;
 
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