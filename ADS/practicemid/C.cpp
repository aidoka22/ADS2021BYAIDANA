#include <iostream>
#include <list>
#include <string>
using namespace std;

void MergeSortA(int low , int high);
void MergeA(int low ,int mid ,int high);

string currentArray[5];
void MergeSortA(int low , int high)
{
    int mid = 0;
    if(low < high)
    {
        mid = ((low+high)/2);
        MergeSortA(low , mid);
        MergeSortA(mid+1,high);
        MergeA(low,mid,high);
    }
}
void MergeA(int low ,int mid , int high)
{
    int i = low, j = mid+1 , k = low;
    string Temp[5];

    while(i <= mid && j <= high)
    {
        if( currentArray[i] < currentArray[j] )
        {
            Temp[k].assign(currentArray[i]);
            i++;
        }
        else
        {
            Temp[k].assign(currentArray[j]);
            j++;
        }
        k++;
    }
    if(i > mid )
    {
        for(int h = j ;h <= high ; h++ )
        {
            Temp[k].assign(currentArray[h]);
            k++;
        }
    }
    else
        for(int h = i; h<= mid ; h++ )
        {
            Temp[k].assign(currentArray[h]);
            k++;
        }
   for(int i = low; i <= high ; i++)
   {
       currentArray[i].assign(Temp[i]);
   }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin >> currentArray[i];

    MergeSortA(0,n-1);
    for(int i = 0; i < n; i++)
        cout << currentArray[i] <<" ";
    return 0;
}
