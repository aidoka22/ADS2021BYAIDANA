#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int a[256][256];
  int n,k, d, z, x, y, o;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> a[i][j];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(i!=j)
        for(k=0; k<n; k++)
          if(k!=j && k!=i && (d=a[i][j]+a[j][k]+a[k][i])<o)
            o=d, z=i, x=j, y=k;
    cout << z+1 << " " << x+1 << " " << y+1;
}