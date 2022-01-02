#include <iostream> 
using namespace std;
int i, j,n;
bool is_tree;
const long long N = (long long)1e5 + 5;
int a[1000][1000];
void BFS(){
    int *queue = new int[n];
    bool *visited = new bool[n];
    int count, head;
    for (i = 0; i<n; i++) queue[i] = 0;
    count = 0;
    head = 0;
    queue[count++] = 0;
    visited[0] = true;
    is_tree = true;
    while (head<count)
    {
        int unit = queue[head++];
        for (i = 0; i<n; i++)
        {
 
            if (a[unit][i])
            {
                if (!visited[i])
                {
                    queue[count++] = i;
                    visited[i] = true;
                }
                else
                {
                    if (!a[i][unit])
                        is_tree = false;
                }
            }
        }
 
    }
    delete[]queue;
    delete[]visited;
}
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    for (i = 0; i<n; i++)
    {
        for (j = 0; j<n; j++)
            cin>> a[i][j];
    }
    BFS();
    if(is_tree==false){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}