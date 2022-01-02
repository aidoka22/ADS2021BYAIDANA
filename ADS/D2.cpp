#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m, min, max, ans = 0;
    vector <int> vmin, vmax;
    cin >> n >> m;           
    vector <vector <int> > arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        max = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] > arr[max][i])
                max = j;
        }
        vmax.push_back(arr[max][i]); 
    }                                
    for (int i = 0; i < n; i++)      
    {                                
        min = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] < arr[i][min]) 
                min = j;
        }
        vmin.push_back(arr[i][min]); 
    }                                
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == vmin[i] && arr[i][j] == vmax[j]) 
                ans++; }
    }
    cout << ans << endl;
}