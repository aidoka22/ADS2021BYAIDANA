#include <iostream>
#include <queue>
 
using namespace std;
 
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int n, m, count=0;
bool a[101][101];
 
bool check(int x, int y) {return ( (0 <= y) && ( y < m) && (0 <= x) && (x<n));}
 
void complete(int start_x, int start_y){
    queue <int> q1, q2;
    q1.push(start_x);
    q2.push(start_y);
    int x, y;
    while(! q1.empty()){
        x = q1.front();
        y = q2.front();
        q1.pop();
        q2.pop();
        a[x][y] = 1;
        for(int i=0; i<4; i++)
            if(check(x+dx[i], y+dy[i]) &&  a[x+dx[i]][y+dy[i]] == false){
                q1.push(x+dx[i]);
                q2.push(y+dy[i]);
            }
    }
}
 
int main(){
    cin >>n>>m;
    char ch;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
          cin >> ch; 
          a[i][j] = ch=='.';
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j] == 0){
                count++;
                complete(i, j);
            }
    cout<<count;
    return 0;
}